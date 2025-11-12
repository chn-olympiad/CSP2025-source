#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s1,s2="";
	cin>>s1;
	for(int i=0;i<(int)s1.size();i++)
		if(isdigit(s1[i])) s2+=s1[i];
	sort(s2.begin(),s2.end(),cmp);
	cout<<s2; 
	return 0;
}
