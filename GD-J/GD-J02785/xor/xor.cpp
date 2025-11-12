#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a[500005];
	int n,k,ans=0;
	cin>>n>>k;
	int cnt=0;
	for(int i=0;i<n;i++) cin>>a[i];
	
	
	for(int l=0;l<n;l++)
	{
		for(int r=l;r<n;r++)
		{
			int ans=0;
			for(int h=l;h<r;h++)
			{
				ans=a[l]^a[r];
			}	
			if(ans==k)
			{
				cnt++;
			}
		}
	}
	cout<<cnt;	
}
