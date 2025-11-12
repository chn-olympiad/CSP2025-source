#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int a[1005],n,m,mi,s,ans1,b;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nm=n*m;
	for(int i=1;i<=nm;i++)
		cin>>a[i];
	mi=a[1];
	sort(a+1,a+1+nm,cmp);
	for(int i=1;i<=nm;i++)
	{
		if(a[i]==mi)
		{
			s=i;
			break;
		}
	}
	double ans=s*1.0/n;
	ans1=ceil(ans);
	cout<<ans1<<" ";
	b=s-n*(ans1-1);
	if(ans1%2==1)
	cout<<b;
	else
	cout<<m-b+1;
	return 0;
}
