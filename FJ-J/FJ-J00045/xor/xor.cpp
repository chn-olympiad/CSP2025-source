#include<bits/stdc++.h>
using namespace std;
int n,p,a[500001],fll[500001],flr[500001];
map<int,int>f[500001];
bool flagg=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>p;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	fll[i]=a[i]^fll[i-1];
    	if(a[i]==0)
    	flagg=0;
	}
	if(flagg)
	{
		if(p)
		cout<<n;
		else
		cout<<n/2;
		return 0;
	}
	flr[n]=a[n];
	for(int i=n-1;i>=1;i--)
    {
    	flr[i]=a[i]^flr[i+1];
	}
	for(int len=1;len<=n;len++)
	for(int i=1;i<=n-len+1;i++)
	{
		int j=i+len-1;
		if((fll[n]^fll[i-1]^flr[j+1])==p)
		f[i][j]=1;
		for(int k=i;k<=j-1;k++)
		{
			f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
		}
	}
	cout<<f[1][n];
	return 0;
}
