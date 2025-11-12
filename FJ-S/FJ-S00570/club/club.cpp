#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,v[N][4],ans;
bool f;
struct cl{
	int x,y,z,id;
}s[N],b[N];
bool cmp(cl x,cl y){
	return x.x>y.x;
}
bool cmp1(cl x,cl y){
	return x.y>y.y;
}
bool cmp2(cl x,cl y){
	return x.z>y.z;
}
int getmax(int x,int y,int z){
	if(x>=y&&x>=z) return x;
	if(y>=x&&y>=z) return y;
	if(z>=x&&z>=y) return z;
}
int getscd(int x,int y,int z){
	if((x>=y&&x<=z)||(x>=z||x<=y)) return x;
	if((y>=x&&y<=z)||(y<=x&&y>=z)) return y;
	if((z>=x&&z<=y)||(z<=x&&z>=y)) return z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		f=false;
		int rem1=0,rem2=0,rem3=0;
		ans=0;
		memset(v,0,sizeof(v));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].z);
			if(s[i].y!=0||s[i].z!=0) f=1;
			b[i].id=i;
			b[i].x=s[i].x;
			b[i].y=s[i].y;
			b[i].z=s[i].z;
		}
		if(!f){
			sort(s+1,s+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=s[i].x;
			printf("%d\n",ans);
			continue;
		}
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n/2;i++) ans+=b[i].x,v[b[i].id][1]=1;
		rem1=b[n/2+1].x;
		sort(b+1,b+1+n,cmp1);
		for(int i=1;i<=n/2;i++) ans+=b[i].y,v[b[i].id][2]=1;
		rem2=b[n/2+1].y;
		sort(b+1,b+1+n,cmp2);
		for(int i=1;i<=n/2;i++) ans+=b[i].z,v[b[i].id][3]=1;
		rem3=b[n/2+1].z;
		for(int i=1;i<=n;i++){
			if(v[i][1]&&v[i][2]&&!v[i][3]) ans-=min(s[i].x,s[i].y);
			if(v[i][1]&&v[i][2]&&v[i][3])
				ans-=min((s[i].x+s[i].y+s[i].z)-getmax(s[i].x,s[i].y,s[i].z),getmax(rem1,rem2,rem3)+getscd(s[i].x,s[i].y,s[i].z));
			if(v[i][1]&&!v[i][2]&&v[i][3]) ans-=min(s[i].x,s[i].z);
			if(!v[i][1]&&v[i][2]&&v[i][3]) ans-=min(s[i].y,s[i].z);
		}
		printf("%d\n",ans);
	}
	return 0;
}
