#include<bits/stdc++.h>
using namespace std;
long long n,t,ans;
int a[100005][3],b[100005];
void dfs(int x,int sx,int sy,int sz,long long w){
	if(sx>n/2) return;
	if(sy>n/2) return;
	if(sz>n/2) return;
	if(x>n){
		ans=max(ans,w);
		return;
	}dfs(x+1,sx+1,sy,sz,w+a[x][0]);
	dfs(x+1,sx,sy+1,sz,w+a[x][1]);
	dfs(x+1,sx,sy,sz+1,w+a[x][2]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool p=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][1]||a[i][2]) p=1;
		}ans=0;
		if(!p){
			for(int i=1;i<=n;i++) b[i]=a[i][0];
			sort(b+1,b+n+1);
			for(int i=1;i<=n/2;i++){
				ans+=b[i];
			}cout<<ans<<endl;
		}else{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
