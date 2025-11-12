#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0;bool f=0;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f?-x:x;
}

long long t,n,a[100005][5],d[5][100005],tot[5],cnt[5];
int f=0;

long long ans;

int mid(int a,int b,int c){
	if(a>b)swap(a,b);
	if(b>c)swap(b,c);
	if(a>b)swap(a,b);
	return b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();ans=0;tot[1]=tot[2]=tot[3]=0;cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			int flag=0;
			a[i][1]=read();a[i][2]=read();a[i][3]=read();			
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])cnt[1]++,flag=1;
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])cnt[2]++,flag=2;
			if(a[i][3]>a[i][1]&&a[i][3]>a[i][2])cnt[3]++,flag=3;
			d[flag][++tot[flag]]=max(a[i][1],max(a[i][2],a[i][3]))-mid(a[i][1],a[i][2],a[i][3]);
		}
		if(cnt[1]>n/2)f=1;
		if(cnt[2]>n/2)f=2;
		if(cnt[3]>n/2)f=3;
		if(f>0){
			sort(d[f]+1,d[f]+tot[f]+1);
			for(int i=1;i<=cnt[f]-n/2;i++)ans-=d[f][i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
