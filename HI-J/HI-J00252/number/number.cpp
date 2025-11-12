#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;int f=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			a[f]=s[i]-'0';
			f++;
		}
	}
	sort(a,a+f);
	for(int i=f-1;i>=0;i--) cout<<a[i];
	return 0;
	fclose(stdin);
	fclose(stdout);
}

