#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e6 + 10;
string s;
int n,len;
char c[N];
bool cmp(char A,char B)
{
	return A > B;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> s;
	n = s.size();
	for(int i = 0;i < n;i++)
		if('0' <= s[i] && s[i] <= '9')
			c[++len] = s[i];
	sort(c + 1,c + 1 + len,cmp);
	int left = 0;
	while(c[++left] == '0');
	if(left > len)
	{
		cout << "0";
		return 0;
	}
	for(int i = left;i <= len;i++)
		cout << c[i];
	return 0;
}
