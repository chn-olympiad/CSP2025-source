#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],t;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')
		{
			t++;
			a[t]=s[i]-'0';
		}
	sort(a,a+t+1,cmp);
	for(int i=0;i<t;i++)
		printf("%d",a[i]);
	return 0;
}
