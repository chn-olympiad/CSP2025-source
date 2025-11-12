#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,k;
int a[MAXN];
int b[MAXN];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k) ans++;
		b[i]=(a[i]^b[i-1]);
	}
	if(k==0)
	{
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n-1;i++)
	{
		if(a[i]==k) continue;
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]==k) break;
			if((b[i-1]^b[j])==k) ans++;
		}
	}
	cout<<ans;
	return 0;
}
