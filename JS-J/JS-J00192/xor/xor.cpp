#include<bits/stdc++.h>
using namespace std;
int n,a[500005],ans,s,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
    {
		if(a[i]==k)
		{
			ans++;
			s=0;
			continue;
		}
		s^=a[i];
		if(s==k)
		{
			ans++;
			s=0;
		}
	}
	cout<<ans;
	return 0;
}
