#include<bits/stdc++.h>
using namespace std;
int n,t,i1,i2,i3;
long long ans;
struct st{
	int x,y,z;
};
int vis[100005][3];
st a[100005];
void dfs(long long sam,int cnt){
	if(i1>n/2||i2>n/2||i3>n/2) return ;
	if(cnt==n+1){
		ans=max(sam,ans);
		return ;
	}
	
	i1++;
	dfs(sam+a[cnt].x,cnt+1);
	i1--;
	i2++;
	dfs(sam+a[cnt].y,cnt+1);
	i2--;	
	i3++;
	dfs(sam+a[cnt].z,cnt+1);
	i3--;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		dfs(0,1);
		cout<<ans;
		ans=0;
		i1=0,i2=0,i3=0;
	}
	return 0;	
}
