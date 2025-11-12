#include <bits/stdc++.h>
using namespace std;
string a;
unsigned long long nu1=1,nu2=1;
int n,m,s[505];
unsigned long long ch(int x)
{
	unsigned long long num=1;
	for(int i=1;i<=x;i++)
	{
		num*=i*num%998244353;
	}
	return num;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	nu1=ch(n);
	nu2=ch(m);
	cout<<nu2/nu1;
	
	return 0; 
 } 
