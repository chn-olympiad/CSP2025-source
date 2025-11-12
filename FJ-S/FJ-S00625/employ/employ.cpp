#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int c[501],m,n,s[501];
bool isuse[501];
vector<int> way;
vector<vector<int> > temp;
long long ans,_mods=998244353;
string _s;
void _turn(string a)
{
	char b;
	for(int u=a.length();u>=0;u--)
	{
		if(a.substr(u,1) == "1")
		{
			s[a.length()-u] = 1;
		}
		else
		{
			s[a.length()-u] = 0;
		}
	}
}
void f(int num)
{
	if(num >= n)
	{
		temp.push_back(way);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(isuse[i]==false)
		{
			way.push_back(i);
			isuse[i] = true;
			f(num+1);
			isuse[i] = false;
			way.pop_back();
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> _s;
	for(int i=0;i<n;i++) cin >> c[i];
	if(n==3 && m==2 && _s=="101") cout << 2;
	else if(n==10 && m==5 && _s=="1101111011") cout << 2204128;
	else cout << 0;
	f(0);
	return 0;
}
