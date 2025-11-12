#include<bits/stdc++.h>
using namespace std;
string s,num;
int n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(isdigit(s[i])) num+=s[i];
	}
	sort(num.begin(),num.end(),greater<char>());
	for(int i=0;i<num.size();i++) cout<<num[i];
}
