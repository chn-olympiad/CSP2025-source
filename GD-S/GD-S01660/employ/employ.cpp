#include<bits/stdc++.h> 
using namespace std;
int a[505],n,m,zero;
string s;
int jc(int n)
{
	if(a[n]!=0)return a[n];
	a[n]=(n*jc(n-1))%998244353;
	return a[n];
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		int c;
		cin>>c;
		if(c==0)zero++;
	}
	a[1]=1;
	cout<<jc(n);
}
