#include<bits/stdc++.h>
using namespace std; 
bool cmp(int x,int y)
{
	return x>=y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	vector<int> num;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			num.push_back(s[i]-'0');
		}
	}
	sort(num.begin(),num.end(),cmp);
	for(int i=0;i<num.size();i++)
	{
		cout<<num[i];
	}
	return 0; 
}
