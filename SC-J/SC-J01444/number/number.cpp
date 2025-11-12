#include<bits/stdc++.h>
using namespace std;
string s,s1;
bool cmp(int x,int y)
{
	return x>y; 
}
int main()
{
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
		{
			s1=s1+s[i]; 
		} 
	}
	sort(s1.begin(),s1.end(),cmp);
	cout<<s1;
	return 0;
}