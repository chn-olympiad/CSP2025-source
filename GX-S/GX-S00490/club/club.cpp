#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
};
node w[100010];
int n;
long long ans=0;
void dfs(int x,int y,int z,int k,long long zhi){
	if(k==n+1)
		ans=max(ans,zhi);
	if(x<n/2)
		dfs(x+1,y,z,k+1,zhi+w[k].a);
	if(y<n/2)
		dfs(x,y+1,z,k+1,zhi+w[k].b);
	if(z<n/2)
		dfs(x,y,z+1,k+1,zhi+w[k].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			w[i].a=0;
			w[i].b=0;
			w[i].c=0;
		}
		for(int i=1;i<=n;i++){
			cin>>w[i].a>>w[i].b>>w[i].c;
		}
		dfs(0,0,0,1,0);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
