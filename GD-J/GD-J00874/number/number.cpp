#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005],len;
void cf()
{
	for(int i=0;i<sizeof(a);i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			b[len]=int(a[i]-'0');
			len++;
		}
	}
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	cf();
	sort(b,b+len,cmp);
	for(int i=0;i<len;i++)
	{
		cout<<b[i];
	}
	return 0;
}
