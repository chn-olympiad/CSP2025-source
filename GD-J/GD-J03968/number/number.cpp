#include<bits/stdc++.h>
using namespace std;
string a;
int num[1000010];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size(),now=0;
	for(int i=0;i<len;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			num[++now]=a[i]-'0';
		}
	}
	sort(num+1,num+now+1,cmp);
	for(int i=1;i<=now;i++)
	{
		cout<<num[i];
	}
	return 0;
}
