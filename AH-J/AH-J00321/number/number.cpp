#include<bits/stdc++.h>
using namespace std;
struct cnm
{
	char p;
	int dx;
}a[1000005];
bool cmp(cnm x,cnm y)
{
	return x.dx>y.dx;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long len=s.size();
	long long cd=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i].dx=(int)s[i]-48;
			cd++;
		}
	}
	sort(a,a+len,cmp);
	for(int i=0;i<cd;i++)
	{
		cout<<a[i].dx;
	}
	return 0;
}
