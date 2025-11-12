#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j = 0,n = s.size();
	for(int i = 0;i < n;i++)
	{
		if('0'<=s[i] && s[i]<='9')
		{
			j++;
			a[j] = s[i]-'0';
		}
	}
	if(j == 0)
	{
		return 0;
	}
	sort(a+1,a+j+1);
	for(int i = j;i >= 1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
