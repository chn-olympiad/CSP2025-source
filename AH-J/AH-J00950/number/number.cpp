#include<bits/stdc++.h>
//luogu:1503820
//topscoding:509
using namespace std;
string s;
vector<int>a;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cin.tie(nullptr);
	cin>>s;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<a.size();++i)
	{
		cout<<a[i];
	}
	return 0;
}
/*
 CCCC   CCCC  FFFFF
C      C      F
C      C      FFFF
 CCCC   CCCC  F



			A        CCCCC
		   A A      C    
		  A   A     C
		 AAAAAAA    C    
		A       A    CCCCC
*/
