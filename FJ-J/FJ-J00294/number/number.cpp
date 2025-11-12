#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[1000],l=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]<='9'&&s[i]>='0')
			a[l++]=s[i]-'0';
	sort(a,a+l);
	for(int i=l-1;i>=0;i--)
		cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
