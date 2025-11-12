#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],l=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			l++;
			a[l]=s[i]-'0';
		}
	}
	sort(a+1,a+1+l);
	for(int i=l;i>=1;i--) cout<<a[i];
	return 0;
}
