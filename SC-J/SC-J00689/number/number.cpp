#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int f=1;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int x=int(s[i])-48;
			a[f]=x;
			f++;
		}
	}
	sort(a+1,a+f);
	for(int i=f-1;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}