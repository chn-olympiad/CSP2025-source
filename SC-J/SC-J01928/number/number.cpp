#include <bits/stdc++.h>
using namespace std;
string s;
bool is_num(char c){
	return c>='0'&&c<='9';
}
int H[16];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(is_num(s[i]))H[s[i]-'0']++;
	}
	for(int k=9;k>=0;k--)
	{
		while(H[k])
		{
			cout<<k;
			H[k]--;
		}
	}
	return 0;
} 