#include<bits/stdc++.h> 
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{	freopen("number","5",cin);
	freopen("number.out","5",cout);
	string s;cin>>s;
	vector<int> num;

	int ans=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9'){
			 num.push_back(int(s[i]-48));ans++;
		}
	}
	sort(num.begin(),num.end(),cmp);
	for(int i=0;i<ans;i++)
	{
		cout<<num[i];
	}
	return 0;
}
