#include<bits/stdc++.h>
using namespace std;
string s;
int f[1000005];
long long sum;
int main()
{
	freopen("number.out","r",stdout);
	freopen("number.in","w",stdin);
	cin>>s;
	int x=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			f[++x]=s[i]-'0';
		}
	}
	sort(f+1,f+x+1);
	for(int i=x;i>=1;i--)
	{
		sum=sum*10+f[i];
	}
	cout<<sum;
	return 0;
}