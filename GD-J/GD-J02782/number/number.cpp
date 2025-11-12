#include<iostream>
using namespace std;
string s;
int n,a[19];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=1;i<=n;++i)
	{
		if(s[i-1]>='0'&&s[i-1]<='9')
		{
			++a[(int)(s[i-1]-'0')];
		}
	}
	for(int i=9;i>=0;--i)
	{
		for(int j=1;j<=a[i];++j)
		{
			cout<<i;
		}
	}
	return 0;
}
