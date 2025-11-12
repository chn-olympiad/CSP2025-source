#include<bits/stdc++.h>
using namespace std;
string a[1000000];
bool b[1000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[i]=s[i];
			b[i]=1;
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
