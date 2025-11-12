#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int a[11],sl;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sl=s.size();
	for(int i=0;i<sl;i++)
	{
		if(s[i]>='0' and s[i]<='9')a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			printf("%d",i);
		}
	}
	return 0;
}
