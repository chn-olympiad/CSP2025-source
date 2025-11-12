#include<bits/stdc++.h>
#define max_n 1000005
using namespace std;
string a;
int n[max_n];
int cnt=0; 
int cnt_0=0;
int sum=0;
int cmp(int x,int y)
{
	return x>y;
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
			if(a[i]=='0')
			{
				cnt_0++;
				continue;
			}
			cnt++;
			n[cnt]=a[i]-'0';
		}
	}
	sort(n+1,n+1+cnt,cmp);
	for(int j=1;j<=cnt;j++)
	{
		cout<<n[j];
	}
	for(int j=1;j<=cnt_0;j++)
	{
		cout<<"0";
	}
	return 0;
}
