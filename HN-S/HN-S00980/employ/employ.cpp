#include<iostream>
#define ll long long
using namespace std;
ll ex(ll a,ll b,ll c)
{
	if(a == 1) return b;
	ll ans = ((b - ex(c % a,b,a)*c)/a)%c;
	while(ans <= 0) ans+=c;
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll a,b,i,t = 1,k = 1;
	cin >> a >> b;
	string str;
	cin >> str;
	ll c[a+1];
	for(i = 1;i <= a;i++)
		cin >> c[i];
	for(i = 2;i <= a;i++)
	{
		t = (t * i) % 998244353;
		if(i == (a-b)) k = t;
	}
	cout << ex(k,t,998244353);
	return 0;
}
