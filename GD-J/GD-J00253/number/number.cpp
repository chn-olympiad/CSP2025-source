#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e+6;
int a[N];
int main()
{
	freopen("stdin.number","r",stdin);
	freopen("stdout.number","w",stdout);
	string s;
	cin>>s;
	int len=0;
	for(int i=0;i<=N;i++)
	{
		if(!s[i])
		{
			break;
		}
		else
		{
			len++;
		}
	}
	int n=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
