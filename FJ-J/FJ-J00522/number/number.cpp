#include <bits/stdc++.h>
using namespace std;
vector<long long> numCount(10,0);
vector<char>num{'0','1','2','3','4','5','6','7','8','9'};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	for(int i=0;i<str.length();i++)
		for(int j=0;j<10;j++)
		if(str[i]==num[j])
		numCount[j]++;
	for(int i=9;i>=0;i--)
	while(numCount[i]!=0)
	{
		cout<<num[i];
		numCount[i]--;
	}
	return 0;
}
