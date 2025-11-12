#include<algorithm>
#include<iostream>
using namespace std;
int n,a[5010],s,ans,m;
bool vis[5010];
void dfs(int g,int c,int sum){
	if(sum>m*2) ans++;
	if(g==3||c>n) return;
	for(int i=c+1;i<n;i++){
		vis[i]=1;
		dfs(g-1,i,sum-a[i]);
		vis[i]=0;
	}
	for(int i=c;i>=1;i--) if(!vis[i]) m=a[i];
	vis[n]=1;
	dfs(g-1,n,sum-a[n]);
	vis[n]=0;
	m=a[n];
}
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	sort(a+1,a+1+n);
	m=a[n];
	dfs(n,0,s);
	cout<<ans;
	return 0;
}
