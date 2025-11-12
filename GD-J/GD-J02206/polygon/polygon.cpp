#include<bits/stdc++.h>
#define N 5005
#define MOD 998244353
using namespace std;
int n;
int a[N];
int s[N];
int get(int l,int r)
{
	return s[r]-s[l-1];
}
int dfs(int x,int t,int p)
{
	if(x>n)return 0;
	int sum=0;
	if(a[x]<t && p>=2)sum++;
	sum+=dfs(x+1,t+a[x],p+1)+dfs(x+1,t,p);
	return sum%MOD;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	cout<<dfs(1,0,0);
	return 0;
}
/*
5
2 2 3 8 10
*/
