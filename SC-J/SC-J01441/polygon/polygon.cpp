#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::freopen;
const int N=5e3+6,MOD=998244353;
int n,k,a[N];
int dfs(int pos,int sum,int depth,int max,int n,int a[])
{
	int ans=0;
	if(depth>=3&&sum>max*2)
		ans=(ans+1)%MOD;
	if(pos==n-1&&sum<=a[n-1])
		return 0;
	if(pos>=n)
		return ans;
	for(int i=pos;i<n;i++)
		ans=(ans+dfs(i+1,sum+a[i],depth+1,a[i],n,a))%MOD;
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("poligon.out","w",stdout);
	cin>>n;
	bool b=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)
			b=false;
	}
	std::sort(a,a+n);
	cout<<dfs(0,0,0,0,n,a);
	return 0;
}