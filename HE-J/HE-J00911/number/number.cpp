#include <bits/stdc++.h>
using namespace std;

int main()
{

	freopen("number.in","r",stdin);
	freopen("number.ans","r",stdout);
	string s;
	for(int i=1;i<=3;i++)
	{
		cin>>s[i];
		if(s[i]>s[i+1]) s[1]=s[i];
		else if(s[i]<s[i+1]) s[1]=s[i+1];
		else s[1]=s[i]; s[2]=s[i+1];
	    cout<<s;
	
	}
	
	return 0;
}
