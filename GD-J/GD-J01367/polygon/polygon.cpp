#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001],b[5001];
long long jc(int e,int d)
{
	long long ans1=1;
	for(int i=(e-d);i<=e;i++) ans1=(ans1*i)%998244353;
	return ans1;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long ans=0;
	for(int i=3;i<=n;i++) ans=(ans+jc(n,i))%998244353;
	cout<<ans;
	return 0;
} 
//beng huai xing qiong tie dao 118496512
 
