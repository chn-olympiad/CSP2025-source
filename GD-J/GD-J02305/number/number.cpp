#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

string s;
int a[100];
int main(int argc, char** argv) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;
	for(int i = 0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	for(int i = 9;i>=0;i--)
	{
		while(a[i])
		{
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
