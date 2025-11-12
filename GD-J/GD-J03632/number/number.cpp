#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int i,a[10]={0,0,0,0,0,0,0,0,0,0};
	cin>>s;
	for(i=0;i<s.length();i++)
		if(s[i]<='9'&&s[i]>='0')
			a[s[i]-'0']++;
	for(i=9;i>=0;i--)
		while(a[i]>0)
		{
			cout<<i; 
			a[i]--;
		}
	return 0;
}
