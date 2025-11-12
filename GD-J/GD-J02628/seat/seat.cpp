#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int a1,int a2)
{
	return a1>a2;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++)
	{
		cin>>a[i];
	}
	int A=a[1];
	sort(a+1,a+1+len,cmp);
	int tmp=0;
	for(int i=1;i<=len;i++)
	{
		if(a[i]==A)
		{
			tmp=i;
			break;
		}
	}
	cout<<(tmp-1)/n+1;
	if((tmp-1)%(2*n)<n)
	{
		cout<<' '<<(tmp-1)%(2*n)+1;
	}
	else
	{
		cout<<' '<<2*n-(tmp-1)%(2*n);
	}
}
