#include<iostream>
using namespace std;
int t[15];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(char c:s)
	{
		if(c>='0'&&c<='9')
			t[c-'0']++;
	}	
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=t[i];j++)
			cout<<i;
	}
	return 0;
}
//use cin&&cout
//if close don't use scanf&&printf
