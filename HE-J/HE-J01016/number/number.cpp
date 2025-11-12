#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char b;
	cin>>s;
	int j=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[j]=s[i];
			j++;
		}
	}
	sort(a+1,a+j+1);
	for(int i=j;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
