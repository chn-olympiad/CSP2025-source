#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+5],x[n+5]={0},t=1,ans=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=t;j<=i;j++)
		{
			x[j]=x[j]^a[i];
			if(x[j]==k) 
			{
				ans++;
				for(int z=t;z<=i;z++)
					x[z]=0;
				t=i+1;
				break;
			}
		}
	cout<<ans;
}
