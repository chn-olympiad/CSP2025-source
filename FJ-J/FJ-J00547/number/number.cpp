#include<bits/stdc++.h>
using namespace std;
long long int a[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			a[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i])
		{
			a[i]--;
			printf("%d",i++);
		}
	}
	return 0;
}
