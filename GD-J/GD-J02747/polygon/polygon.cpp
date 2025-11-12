#include<bits/stdc++.h>
using namespace std;
int sum,n,k;
int a[5200];
void dfs(int num,int u,int x,int y) {
	if(u==k) {
		if(num>x*2) sum++;
		return;
	}
	if(y>n)return;
	dfs(num+a[y],u+1,a[y],y+1);
	dfs(num,u,x,y+1);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(k=3; k<=n; k++)
		dfs(0,0,0,1);
	cout<<sum%998244353;
	return 0;
}
