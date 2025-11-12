#include<bits/stdc++.h>
using namespace std;
long long b,c,d;
string s;
char a[1000010];
int main()
{
	fropen("number.in","r",stdin);
	fropen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		  a[i]=s[i];
	}
	sort(a,a+s.size());
	for(int i=s.size()-1;i>=0;i--)
		cout<<a[i];
	return 0;
	fclose(stdin);
	fclose(stdout);
}
