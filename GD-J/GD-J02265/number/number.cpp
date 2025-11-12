#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000010];
bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num[++cnt]=int(s[i]-'0');
		}
	}
	sort(num+1,num+1+cnt,cmp);

	for(int i=1;i<=cnt;i++)
	{
		cout<<num[i];
	}
}
