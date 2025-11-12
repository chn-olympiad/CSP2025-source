#include<bits/stdc++.h>
using namespace std;
int a[10010],n,sss;
long long dfs(int wwz,int wz,int bs,int sum,int sum1)//外面位置，位置，边数
{
	if(wz==bs-1&&sum1<sum)
	{
		return 1;
	}
	if(wz==bs-1)
	return 0;
	int ss=0;
	for(int i=1;i<wwz;i++)
	{
		ss+=dfs(i,wz+1,bs,sum+a[i],sum1);
	}
	return ss;
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			sss+=dfs(j,0,i,0,a[j]);
			sss=sss%998244353;
		}
	}
	cout<<sss;
	return 0;
}

