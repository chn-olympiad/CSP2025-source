#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+50;
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
	cin>>s;
	int l=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') 
		{
			l++;
			a[l]=s[i]-'0';
		}
	}
	sort(a+1,a+1+l,cmp);
	for(int i=1;i<=l;i++)
	{
		cout<<a[i];
	}
	return 0;
}
