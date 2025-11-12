#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[2000000],a1[2000000];
	cin>>n>>k;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i!=0)
		a1[i]=a1[i-1]^a[i];
		else a1[i]=a[i];
	} 
	for(int l=0;l<n;l++)
	{
		for(int r=l;r<n;r++)
		{
			if(l==r)
			{
				if(a1[l]==k)
				{
					cnt++;
					l=r;
					break;
				}
			} 
			if(l!=0 && (a1[r]&a[l-1])==k)
			{
				cnt++;
				l=r;
				break;
			}
			else if(l==0&&a1[r]==k)
			{
				cnt++;
				l=r;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}

