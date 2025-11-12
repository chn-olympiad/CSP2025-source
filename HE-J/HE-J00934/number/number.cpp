#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int x[MAXN];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int j=0;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			x[++j]=s[i]-'0';
		}
	}
	sort(x+1,x+j+1,greater<int>());
	for(int i=1;i<=j;i++)
	{
		cout<<x[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
