#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool cmp(char n1,char n2)
{
	return n1>n2;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s2="";
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
		{
			s2+=s[i];
		}
	}
	sort(s2.begin(),s2.end(),cmp);
	cout<<s2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
