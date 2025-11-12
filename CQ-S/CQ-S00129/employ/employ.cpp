#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int NR = 510;
const ll MOD = 998244353;
int c[NR];

bool chk(string s)
{
	for(int i=0;i<=s.size()-1;i++)if(s[i] == '0')return false;
	return true; 
}

int main()
{
	freopen("employ.in" , "r" , stdin); 
	freopen("employ.out" , "w" , stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(chk(s))
	{
		ll mul = 1;
		for(ll i=1;i<=n;i++)//i:第i天有多少个人可以来测试 
		{
			mul = (mul * i) % MOD;
		}
		cout<<mul<<endl;
		return 0;
	}
	return 0;
}
/*
思路1：
特殊性质A，20pts，推导数学公式 
不管第i天叫谁来都能通过测试，没有人会淘汰 
*/
