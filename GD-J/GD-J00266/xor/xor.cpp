#include<bits/stdc++.h>
using namespace std;
int n,k,a[50005];
int Xor(int l,int r)
{
	int ans=0;
	for(int i = l;i<=r;i++)
	{
		ans^=a[i];
	}
	return ans;
}
int main()
{
	int l=0,r=0,ans=0;
	freopen("xor4.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	for(;r<n;r++)
	{
		if(Xor(l,r)==k||a[r]==k)
		{
			ans++;
			l=++r;
		}
	}
	cout<<ans;
	return 0;
}
