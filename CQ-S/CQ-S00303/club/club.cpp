#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,d[N][4],ans,a[N*3+5];
struct baga{
	int num,c;
}c[N];
void dfs(int now,int a,int b,int c,int cnt){
	if(now==n+1){
		ans=max(ans,cnt);
		return;
	}
	if(a+1<=n/2)dfs(now+1,a+1,b,c,cnt+d[now][1]);
	if(b+1<=n/2)dfs(now+1,a,b+1,c,cnt+d[now][2]);
	if(c+1<=n/2)dfs(now+1,a,b,c+1,cnt+d[now][3]);
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		memset(d,0,sizeof d);
		bool xa=0,xb=0,xc=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)cin>>d[i][j],a[i*j]=d[i][j];
			if(d[i][1])xa=1;
			if(d[i][2])xb=1;
			if(d[i][3])xc=1;
		}
		if((xb==xc&&xc==0)||(xa==xb&&xb==0)||(xa==xc&&xc==0)){
			sort(a+1,a+n+n+n+1,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++)ans+=a[i];
			cout<<ans<<"\n";
			continue;
		}
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
		}
		else{
			if(xc==0){
				for(int i=1;i<=n;i++)c[i]={d[i][2],d[i][2]-d[i][1]};
				sort(c+1,c+n+1,[](baga x,baga y){
					return x.c>y.c;
				});
				for(int i=1;i<=n/2;i++)ans+=c[i].num;
				for(int i=n/2+1;i<=n;i++)ans+=(c[i].num-c[i].c);
				cout<<ans<<"\n";
			}
			else{
				for(int i=1;i<=n;i++){
					ans+=max({d[i][1],d[i][2],d[i][3]});
				}
				cout<<ans<<"\n";
			}
		}
		ans=0;
	}
	return 0;
}

