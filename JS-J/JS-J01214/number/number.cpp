#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
ll a[20];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(char c:s)
	{
		if('0'<=c && c<='9')
			a[(c-'0')]++;
	}
	for(ll i=9;i>=0;--i)
		if(a[i])
		{
			for(ll j=1;j<=a[i];++j)
				printf("%lld",i);
		}
	puts("");
	return 0;
}
// 8:40 T1+100
