#include<bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cum=1;
	cin>>s;
	int p=s.size();
	for(int i=0;i<p;i++)
	{
		if(isdigit(s[i]))
		{
			a[cum]=s[i]-'0';
			cum++;
		}
	}
	sort(a+1,a+cum+1,cmp);
	for(int i=1;i<cum;i++)
	{
		cout<<a[i];
	}
	return 0;
}
