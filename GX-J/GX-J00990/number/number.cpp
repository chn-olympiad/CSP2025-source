#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

bool cmp(int &a, int &b)
{
	return a>b;
}

string s;
int a[100005],k=0;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++)
	{
		if(isdigit(s[i]))
		{
			a[k]=s[i]-48;
			k++;
		}
	}
	sort(a,a+k,cmp);
	for(int i=0;i<k;i++)
	{
		cout<<a[i];
	}
	return 0;
}
