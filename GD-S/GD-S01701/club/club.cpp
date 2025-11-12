#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}a[100005];
int n,ans;
bool cmp(node a,node b){
	if(a.a!=b.a)return a.a>b.a;
	else if(a.b!=b.b)return a.b>b.b;
	return a.c>b.c;
}
void dfs(int i,int x,int y,int z,int sum){
	if(i==n+1){
		ans=max(ans,sum);
		return ;
	}
	if((x+1)*2<=n)dfs(i+1,x+1,y,z,sum+a[i].a);
	if((y+1)*2<=n)dfs(i+1,x,y+1,z,sum+a[i].b);
	if((z+1)*2<=n)dfs(i+1,x,y,z+1,sum+a[i].c);
}
void sol(){
	cin>>n;
	memset(a,0,sizeof a);
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[i]={x,y,z};
	}
	sort(a+1,a+n+1,cmp);
	ans=0;
	dfs(1,0,0,0,0);
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		sol();
	}
	return 0;
}
//club
