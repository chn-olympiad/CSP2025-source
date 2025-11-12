#include<bits/stdc++.h>
using namespace std;
long long n,b=-1; 
char a[1000100];
string s;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(long long i=0;i<n;i++)
	{
		if(isdigit(s[i]))
		{
			b++;
			a[b]=s[i];

		}
	}
	sort(a,a+b+1,cmp);
	for(int i=0;i<=b;i++)
	{
		cout<<a[i];
	}
	return 0;
}
