#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll t[10];

string s;

int main( )
{ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>s;
	
	ll k = s.size( ) - 1;

	for(ll i = 0;i <= k;i ++)
	{
        if(s[i] >= '0' && s[i] <= '9')
        {
            t[s[i] - '0'] ++;
        }
	}

	for(ll i = 9;i >= 0;i --)
	{
        if(t[i] != 0)
        {
			for(ll j = 1;j <= t[i];j ++)
			{
				cout<<i;
			}
		}
    }

	return 0;
}
