#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
			sum++;
			a[i]=-1;
    }
	for(int l=1;l<=n;l++)
	{
		if(a[l]==-1)
			l++;
		for(int r=l;r<=n;r++)
		{
			if(a[r]==-1)
				l++;
			int cnt=a[l];
			for(int i=l+1;i<=r;i++)
			{
				cnt^=a[i];
			}
			if(cnt==k)
				sum++;
		}
	}
	cout<<sum;
	fclose(stdin);
    fclose(stdout);	
	return 0;
 } 
