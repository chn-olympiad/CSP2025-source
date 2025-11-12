#include <bits/stdc++.h>

using namespace std;

int cnt[10];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	string str; cin >> str;
	for (int i=0;i<str.length();i++) 
	{
		char ch=str[i];
		if ('0'<=ch && ch<='9') cnt[ch-'0']++;
	}
	
	string res="";
	for (int i=9;i>=0;i--) 
	{
		char ch='0'+i;
		for (int j=0;j<cnt[i];j++) res+=ch;
	}
	cout << res << "\n"; 
	 
	return 0;
}
