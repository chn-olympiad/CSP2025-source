#include <bits/stdc++.h>
using namespace std;
string s;
int c[600];
int A(int n,int m)
{
	long long x=1;
	for(int i=m;i>=n+1;++i) x*=i;
	return x%998244353; 
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;int ans=0;cin>>n>>m;	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];if(c[i]==0)ans++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)if(c[j]>c[j+1])swap(c[j],c[j+1]); 
	}

	int w=1;
	for(int i=0;i<n;i++)
	{
		if(s[i]==0) w=0;
	}
	if(w==1) {
		int x=A(0,n-ans)+A(0,ans);
		cout<<x;
		return 0;
	}
	return 0;
} 
