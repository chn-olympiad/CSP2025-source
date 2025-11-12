#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=998244353;
int n,m,s,ok,a[505],b[505],vis[505];
string x;
bool f(){
	int cnt=0,cnt2=0;
	for(int i=1; i<=n; i++)
	{
		if(a[b[i]]<=cnt2)
		{
			cnt2++;
			continue;
		}
		if(x[i]=='1')
			cnt++;
		else
			cnt2++;
	}
	return cnt>=m;
}
void dfs(int cnt){
	if(cnt==n+1)
	{
		if(f())
			s++;
		return;
	}
	for(int i=1; i<=n; i++)
		if(!vis[i])
		{
			vis[i]=1;
			b[cnt]=i;
			dfs(cnt+1);
			vis[i]=0;
		}
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>x;
    x=" "+x;
    for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		if(x[i]=='1')
			ok++;
	}
	if(ok<m)
	{
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<s;
    return 0;
}
