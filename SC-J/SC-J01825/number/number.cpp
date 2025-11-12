#include<bits/stdc++.h>
using namespace std;	
string s;
char a[10000010];
int k=0;
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
		{
			a[k]=s[i];
			k++;
		}
	}
	sort(a,a+k+1,cmp);
	for(int i=0;i<k;i++)
	{
		cout<<a[i];
	}
	return 0;
}