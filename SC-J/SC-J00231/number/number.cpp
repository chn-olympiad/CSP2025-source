# include"bits/stdc++.h"
using namespace std;
int main()
{	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long a[10];
	memset(a,0,sizeof(a));
	cin>>s;
	for(int i=0;i<s.length();i++)
		if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(a[i]>0)
			{a[i]--;
			cout<<i;}
	return 0;
}