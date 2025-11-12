#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b)
{
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,t = "";
	cin>>s;
	for(int i = 0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')t = t+s[i];
	}
	sort(t.begin(),t.end(),cmp);
	cout<<t;
	return 0;
}
