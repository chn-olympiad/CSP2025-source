#include<bits/stdc++.h>
using namespace std;
int f(char a)
{
	return a-'0';
}
bool cmd(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int a[100005];
	int k=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]<='9'||a[i]>='0')
		{
			a[k]=f(s[i]);
			k++;
		}
	}
	sort(a+0,a+k,cmd);
	for(int i=0;i<k;i++)
	{
		cout<<a[i];
	}
	return 0;
}
