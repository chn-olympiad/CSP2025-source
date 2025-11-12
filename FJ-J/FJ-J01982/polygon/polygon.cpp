#include<bits/stdc++.h>
using namespace std;
const int N=5010;
const int M=998244353;
int n,a[N],ans;
inline void dfs(int x,int y)
{
	if(x==n+1){
		return;
	}
	if(y>a[x]){
		ans++;
		ans%=M;
	}
	dfs(x+1,y);
	dfs(x+1,y+a[x]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	dfs(1,0);
	cout<<ans%M;
	return 0;
}
