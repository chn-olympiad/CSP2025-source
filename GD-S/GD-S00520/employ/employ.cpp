#include<bits/stdc++.h>
using namespace std;
int n,m,c[1000],tmp;
string s;
const int maxn = 998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
		if(c[i] == 0) cnt++; 
	}
	int len = s.length(),fl = 1;
	for(int i = 0;i < len;i++)
	{
		if(s[i] != '1') fl = 0;
	}
	long long sum = 1;
	for(int i = 1;i <= n - cnt;i++)
	{
		sum *= i % maxn;
		sum %= maxn; 
	}
	cout << sum << endl;
	
	return 0;
 } 
 //Ren5Jie4Di4Ling5%
