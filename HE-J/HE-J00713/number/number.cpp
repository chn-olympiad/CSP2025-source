#include<bits/stdc++.h>
#include<cstdio>
#include<cctype>
using namespace std;

const int N=1e6+5;

string s;
int a[N];
bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=0;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	//sort(a+1,a+n+1,cmp);
	for(int i=9;i>=0;i--)
	{
		while(a[i]--)
		{
			cout<<i;
		}
	}
	return 0;
}
