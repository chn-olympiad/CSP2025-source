#include<bits/stdc++.h>
using namespace std;
int s[2000000],l=1;
int a[500005],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=a[i]^a[i-1];
		int m=k^a[i];
		if(m==0||s[m]>=l)
		{
			l=i+1;
			ans++;
			a[i]=0;
		}
		else
		{
			s[a[i]]=i;
		}
	}
	cout<<ans;
	return 0;
}
