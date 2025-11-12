#include <bits/stdc++.h>
using namespace std;
const int N=1e6+100;
string s;
long long a[N],h = 0;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> s;
	for(int i=0;i<s.size();++i) 
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[h] = s[i] - '0';
			h ++;
		}
	}
	sort(a+0,a+0+h,cmp);
	for(int i=0;i<h;i++)
	{
		cout << a[i];
	}
	return 0;
}
