#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];//aÓÃÀ´´¢´æÊý×Ö 
int num, c;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[num]+=s[i]-'0';
			num++;
		}
	}
	sort(a,a+num,cmp);
	for (int i=0;i<num;i++)
	{
		c*=10;
		c+=a[i];
	}
	cout<<c;
	return 0;
}
