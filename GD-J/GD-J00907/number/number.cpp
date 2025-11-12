#include<bits/stdc++.h>
using namespace std;
string s;
int t[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int a=(int)(s[i]-'0');
			t[a]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(t[i])
		{
			printf("%d",i); 
			t[i]--;
		}
	}
	return 0;
}
