#include<bits/stdc++.h>
using namespace std;
string a;
int n[1000005],sum;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			n[i]=a[i]-'0';
			sum++;
		}
	}
	/*for(int i=sum-1;i>=0;i--)
	{
		cout<<n[i];
	}
	cout<<endl;*/
	sort(n,n+len,cmp);
	for(int i=0;i<sum;i++)
	{
		cout<<n[i];
	}
	return 0;
}
