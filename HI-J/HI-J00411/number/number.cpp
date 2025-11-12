#include<bits/stdc++.h>
using namespace std;
string s;
int n=0;
int b[110000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)if(s[i]>='0'&&s[i]<='9')b[n++]=s[i]-48;
	sort(b,b+n);
	for(int i=n-1;i>=0;i--)cout<<b[i];
	return 0;
}
