#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],k=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a+0,a+k+1);
	for(int i=k;i>0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
