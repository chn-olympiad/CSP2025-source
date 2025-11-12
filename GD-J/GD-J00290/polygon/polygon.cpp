#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int ans[5005],s;
void dfs(int m,int i,int f){
	if(i>m){
		int cnt=0,maxx=0;
		for(int j=1;j<=m;j++)cnt+=ans[j],maxx=max(maxx,ans[j]);
		if(cnt>maxx*2){
			s++;
		}
		return ;
	}
	for(int j=f+1;j<=n;j++){
		ans[i]=a[j];
		dfs(m,i+1,j);
		ans[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++)dfs(i,1,0);
	cout<<s%998244353;
	return 0;
} 
