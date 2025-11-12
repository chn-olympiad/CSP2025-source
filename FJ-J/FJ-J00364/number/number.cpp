#include<bits/stdc++.h>
using namespace std;
string s;
int l=0,a[1000005];
void xsort(int n)
{
	if(l==0)
	{
		a[0]=n;
		l++;
		return;
	}
	for(int i=l-1;i>=0;i--)
	{
		if(a[i]<n)
			a[i+1]=a[i];
		else
		{
			a[i+1]=n;
			l++;
			return;
		}
		if(i==0)
		{
			a[0]=n;
			l++;
			return;
		}
	}

}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>=0)
			xsort(int(s[i])-48);
	}
	for(int i=0;i<l;i++)
		cout<<a[i];
	return 0;
}
