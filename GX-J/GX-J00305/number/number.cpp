#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string s;
int a[1000010];
bool cc(int x,int y)
{
		return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=0;
	int l=s.size();
	for(int i=0;i<=l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			n++;
			a[n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1,cc);
	for(int i=1;i<=n;i++)
		cout<<a[i];
	return 0;
}
