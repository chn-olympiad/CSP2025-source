#include<bits/stdc++.h>
using namespace std;
int n,m,r,rn,rm;
struct node
{
	int fs,id;
}a[100010];
bool cmp(node x,node y)
{
	return x.fs>y.fs;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].fs;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[(i-1)*m+j].id==1)
			{
				r=(i-1)*m+j;
				break;
			}
		}
	}
	rn=ceil(r*1.0/n);
	if(rn&1)rm=r-(rn-1)*n;
	else rm=m-(r-(rn-1)*n)+1;
	cout<<rn<<" "<<rm;
	return 0;
}
