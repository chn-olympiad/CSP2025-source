#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()//Ô¤¼Æ100pts 
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s; 
	vector<int> num;
	for(char c : s)
	{
		if(c >= '0' && c <= '9')
			num.push_back(c-'0');
	}
	sort(num.rbegin(),num.rend());
	string ans = "";
	for(int i : num) ans += (i+'0');
	if(ans[0] == '0' && ans.length() > 1)
		cout<<0;
	else
		cout<<ans;
	return 0;	
} 
