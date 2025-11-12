#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","r",stdout);
	long long int n,k;
	cin>>n>>k;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int t=a[i];
		for(int j=1;j<=n-i;j++)
		{
			for(int x=i;x<=i+j;x++)
			{
				t=int(t^a[x]);
			}
			if(t==k)
			{
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

