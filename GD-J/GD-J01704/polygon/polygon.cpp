#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
long long n,num[50001];
long long sum,maxx;
void dfs(int index,int x,int l,long long maxx)
{
	if(index>n)
	{
		if(l>2*maxx && x>=3)
		{
			sum++;
			sum%N;
		}
		return;
	}
	dfs(index+1,x+1,(l+num[index])%N,max(maxx,num[index]));                                                                                
	dfs(index+1,x,l,maxx);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	dfs(1,0,0,0);
	cout<<sum%N;
}
