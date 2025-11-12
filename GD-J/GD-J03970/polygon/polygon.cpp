#include<bits/stdc++.h>
using namespace std;
int n,a[5010],s;
void dfs(int ii,int m,int sum)//ii=从下标为ii的元素开始查询;m=记录到第m个元素;sum=已记录的元素和 
{
	for(int i=ii;i<=n;i++)
	{
		if(m>=3&&sum+a[i]>a[i]*2)s=(s+1)%998244353;
		dfs(i+1,m+1,sum+a[i]);
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,1,0);
	cout<<s;
	return 0;
}
//过样例1~3 共4个样例 
