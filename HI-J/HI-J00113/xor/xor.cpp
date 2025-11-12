#include<bits/stdc++.h>
using namespace std;
int a[500010];
int s[500010];
bool f[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(s[j]-s[i-1]==k) cnt++; 	 	 
		}
		
	}
	cout<<cnt;
	return 0;
}
