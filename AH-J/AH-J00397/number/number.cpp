#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ch[128],ans;
string a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(ll i=0;i<int(a.size());i++)
	{
		ch[int(a[i])]++;
	}
	for(ll i=57;i>=48;i--)
	{
		while(ch[i]--)
		{
			cout<<i-48;
		}
	}
	cout<<ans;
	return 0;
}
