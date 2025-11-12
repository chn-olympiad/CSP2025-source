#include<bits/stdc++.h>
using namespace std;
int n,k,k1[1100];
int a[1100],ax[1100][1100];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		k1[a[i]]++;
		ax[i][i]=0;
	}
	if(k1[1]==n)
	{
		if(k==0)
		cout<<n;
		else
		cout<<0; 
	}
	return 0;
}
