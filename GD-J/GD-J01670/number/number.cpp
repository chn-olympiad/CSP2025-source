#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MaxN=1e6+10;
string st;
ll a[MaxN],n;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	ll len = st.size();
	for(ll i=0; i<len; i++)
	{
		if(st[i]>='0'&& st[i]<='9')
		{
			a[++n]= (st[i]-'0');
		}
	}
	sort( a+1, a+1+n);
	for(ll i=n; i>=1; i--)
	{
		cout<<a[i];
	}
	return 0;
}
