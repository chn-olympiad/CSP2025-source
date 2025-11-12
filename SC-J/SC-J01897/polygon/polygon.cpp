#include<bits/stdc++.h>
using namespace std;
int n;
//set <long long>cot;
long long cot;
int a[5005],t=3,j[5005];
void dfs(int dep)
{
//	cout<<dep<<" ";
	if(dep>t)
	{
//		cout<<"A";
		long long s=0,ss=1;
//		cout<<"{";
		for(int i=1;i<=t;i++)
		{
			s=s+a[j[i]];
//			ss=ss*+a[j[i]];
//			cout<<a[j[i]];
		}
//		cout<<"}";
		if(s>2*a[j[t]])
		{
//			cout<<"R";
			cot++;
//			cot.insert(ss*s);
//			cout<<s;
		}
		return ;
	}
//	cout<<dep<<" ";
	dep=dep+1;
	for(int i=j[dep-2]+1;i<=n-(t-dep+1);i++)
	{
		j[dep-1]=i;
//		cout<<i<<" ";
		dfs(dep);
//		cout<<6;
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	j[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2)
	{
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	for(;t<=n;t++)
	{
//		cout<<t;
		dfs(1);
	}
	cout<<cot;
//	cout<<cot.size();
	return 0;
} 
