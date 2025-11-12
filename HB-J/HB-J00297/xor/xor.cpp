#include <bits/stdc++.h>
using namespace std;
long long a[500005],n,k,ans,cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	int p=k;
	while(p>=0)
	{
		int l=0,r=p;
		
		while(r<n)
		{
			for(int i=l;i>=r;i--)
			{
				ans=ans^a[i];
			}
			if(ans==k)cnt++;
			l++;
			r++;
		}
		p--;
	}
	cout<<cnt;
	return 0;
}
