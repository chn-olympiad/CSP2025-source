#include<bits/stdc++.h>
using namespace std;
int num[1000002];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int p=0;
	int l=a.size();
	for(int i=0;i<l;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			p++;
			num[p]=a[i]-48;
		}
	}
	sort(num+1,num+p+1,cmp);
	for(int i=1;i<=p;i++)
	{
		cout<<num[i];
	}
	return 0;
}
