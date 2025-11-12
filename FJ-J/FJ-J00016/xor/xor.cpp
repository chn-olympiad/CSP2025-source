#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,h=0,ans=0,s;
	cin>>n>>k;
	for (int i=0;i<n;i++)
	{
		cin>>s;
		h=h^s;
		if(h==k)
		{
			ans++;
			h=0;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
