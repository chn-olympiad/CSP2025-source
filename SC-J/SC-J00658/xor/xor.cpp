#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans=0;
int main(){
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int sum=a[i];
			for(int l=i+1;l<=j;l++)
			{
				sum^=a[l];
			}
			if(sum==k) ans++;
		}
	}
	cout<<ans;
	return 0;
}