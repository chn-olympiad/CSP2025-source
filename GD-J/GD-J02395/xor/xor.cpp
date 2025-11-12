#include<bits/stdc++.h>
using namespace std;
int n,k,a,ans; long long s,t=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(t==0)
		{
			s=a;t=1;continue;
		}
		else if(s==k)
		{
			ans++;s=a;
			continue;
		}
		else if(a==k){
			t=0;ans++;
			continue;
		}
		else
		s=s^a;
	}
	if(s==k)
		ans++;
	cout<<ans;
	return 0;
}
