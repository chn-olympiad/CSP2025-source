#include<bits/stdc++.h>
using namespace std;
long long n,k,f[500005];
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long l=1,r=2,s=0,c=0;
	while(l<r&&l<=n&&r<=n)
	{
		s=a[l];
		if(s==k)
		{
			f[l]=1;
			c++;
			l++;
			r=l+1;
			continue;
		}
		while(r<=n)
		{
			s=(s^a[r]);
			if(a[r]==k&&f[r]==0)
			{
				f[r]=1;
				c++;
				l=r;
				break;
			}
			if(s==k)
			{				
				c++;				
				l=r;
				break;
			}
			r++;
		}
		l++;
		r=l+1;
	}
	cout<<c;
	return 0;
}
