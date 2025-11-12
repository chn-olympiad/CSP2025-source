#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
int a[100005],b[100005],c[100005],vis[5],res=0;
void init(){
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	memset(vis,0,sizeof vis);
	res=0;
}
bool cmp(int x,int y){
	return x>y;
}
void dfs(int sum,int x){
	if(x==n+1){
		res=max(res,sum);
	}
	for(int i=1;i<=3;i++){
		if(vis[i]>=n/2){
			continue;
		}
		vis[i]++;
		if(i==1)dfs(sum+a[x],x+1);
		if(i==2)dfs(sum+b[x],x+1);
		if(i==3)dfs(sum+c[x],x+1);
		vis[i]--;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		init();
		cin>>n;
		int f=1,ff=1,fff=1;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]||c[i]){
				f=0;
			}
			if(a[i]||c[i]){
				ff=0;
			}
			if(a[i]||b[i]){
				fff=0;
			}
		}
		if(f||ff||fff){
			int ans=0;
			sort(a+1,a+1+n,cmp);
			sort(b+1,b+1+n,cmp);
			sort(c+1,c+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				if(f)ans+=a[i];
				if(ff)ans+=b[i];
				if(fff)ans+=c[i];
			}
			cout<<ans<<endl;
		}
		else{
			dfs(0,1);
			cout<<res<<endl;
		}
	}
	return 0;
}
