//GZ-S00259 遵义市第四中学 杨子腾 
#include<bits/stdc++.h>
using namespace std;
int a[500000][3],n;
long long ans;
struct info{
	int d, i;
}d[1000000];
bitset<500000> b;
bool cmp(const info&a,const info&b){
	return a.d > b.d;
}
#define gc getchar()
void read(int& x){
	x=0;
	char c=gc;
	while(!isdigit(c))c=gc;
	while(isdigit(c))x=(x<<3)+(x<<1)+c-'0',c=gc;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		read(n),ans=0;
		long long s0=0,s1=0,s2=0;
		for(int i=0;i<n;i++)read(a[i][0]),read(a[i][1]),read(a[i][2]),
			s0+=a[i][0],s1+=a[i][1],s2+=a[i][2],b[i]=0;
		if(s0>s1&&s0>s2)for(int i=0;i<n;i++)d[i<<1].i=d[i<<1|1].i=i,
			ans+=a[i][0],d[i<<1].d=a[i][1]-a[i][0],d[i<<1|1].d=a[i][2]-a[i][0];
		else if(s1>s0&&s1>s2)for(int i=0;i<n;i++)d[i<<1].i=d[i<<1|1].i=i,
			ans+=a[i][1],d[i<<1].d=a[i][0]-a[i][1],d[i<<1|1].d=a[i][2]-a[i][1];
		else for(int i=0;i<n;i++)d[i<<1].i=d[i<<1|1].i=i,
			ans+=a[i][2],d[i<<1].d=a[i][0]-a[i][2],d[i<<1|1].d=a[i][1]-a[i][2];
		sort(d,d+(n<<1),cmp);
		for(int i=0,cnt=0;d[i].d>0;i++)
			if(!b[d[i].i])b[d[i].i]=1,ans+=d[i].d,cnt++;
		printf("%lld\n",ans);
	}
	return 0;
}
