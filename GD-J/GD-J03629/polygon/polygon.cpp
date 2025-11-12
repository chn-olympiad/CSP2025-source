#include<bits/stdc++.h>
using namespace std;
long long n,l[5001],ch[5001],ans=0;
void dfs(long long dep,long long num)
{
	if(dep>n)
	{
		if(num<3)
		{
			return;
		}
		int x=0;
		for(int i=1;i<num;i++)
		{
			x+=ch[i];
		}
		if(x>2*ch[num-1])
		{
			ans++;
		}
		return;
	}
	dfs(dep+1,num);
	ch[num]=l[dep];
	dfs(dep+1,num+1);
	ch[num]=0;
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>l[i];
	}
	sort(l+1,l+1+n);
	dfs(1,1);
	cout<<998244353%ans;
	return 0;
}
