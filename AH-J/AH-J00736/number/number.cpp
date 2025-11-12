#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int max,d,p;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	d=s.size();
	for(int i=0;i<d;i++)
	{
		if(s[i]-'0'>=0 && s[i]-'0'<=9)
		{
			a[p]=s[i]-'0';
			p++;
		}
	}
	sort(a,a+p);
	for(int i=p-1;i>=0;i--) cout<<a[i];
	return 0;
}
