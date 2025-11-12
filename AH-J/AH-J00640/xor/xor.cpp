#include<bits/stdc++.h>
using namespace std;
int s[1000000];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n,k;
	bool flag=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]>1) flag=1;
	}
	if(k==0)
	{
		cout<<n/2;
		return 0;
	}
	else
	{
		int maxn=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			int tot=0;
			for(int l=1;l<=n-i+1;)
			{
				int sum=s[l];
				if(sum==k)
				{
					tot++;
					l++;
				}
				else
				{	
					for(int f=l+1;f<=l+i-1;f++)
					{
						sum=sum^s[f];
					}
					if(sum==k)
					{
						tot++;
						l=l+i;
					}
					else
					l++;
				}
			}
			maxn=max(maxn,tot);
		}
		cout<<maxn;
	}
    return 0;
}
