#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(!(s[i]>='a' && s[i]<='z'))
		{
			a[cnt]=s[i];
			if(a[cnt]!=0)
			{
				a[cnt]-=48;
			}
			cnt++;
		}
	}
	sort(a,a+cnt);
	reverse(a,a+cnt);
	for(int i=0;i<cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
} 
