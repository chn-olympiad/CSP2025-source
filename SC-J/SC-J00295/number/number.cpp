#include<bits/stdc++.h>
using namespace std;
int num[1000001];
int p=1;
long long ans;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>=48 and s[i]<=57)
		{
			num[p]=s[i]-48;
			p++;
		}
	}
	sort(num+1,num+p,cmp);
	for(int i=1;i<=p-1;i++)
	{
		cout<<num[i]; 
	}
	return 0;
}