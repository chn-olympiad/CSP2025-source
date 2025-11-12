#include <bits/stdc++.h>
using namespace std;
string s;
int num[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=0;
	for (int i=1;i<=1000005;++i)
		num[i]=-1;
	int x=s.size();
	for (int i=0;i<x;++i)
	{
		if (s[i]>='0' && s[i]<='9')
			num[++j]=(int)(s[i]-'0');
	}
	sort(num+1,num+j+1);
	for (int i=j;i>=1;--i)
		cout<<num[i];
	cout<<endl;
	return 0;
}
