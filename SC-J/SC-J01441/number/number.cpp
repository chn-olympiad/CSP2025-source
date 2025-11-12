#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::freopen;
using std::string;
int cnt[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++)
		if(std::isdigit(str[i]))
			cnt[str[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(cnt[i]--)
			cout<<i;
	return 0;
}