#include<bits/stdc++.h>
using namespace std;
int n,m,q,b[101];
int qn=1,qm=1,ja[2]={1,-1};
int jm=0;
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&b[i]);
		if(i==1)
		q=b[i];
	}
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(q==b[i])
		{
			cout<<qn<<" "<<qm;
			return 0;
		}
		if(qm+ja[jm%2]>n)
		{
			jm++;
			qn++;
			continue;
		}
		else if(qm+ja[jm%2]<1)
		{
			jm++;
			qn++;
			continue;
		}
		qm+=ja[jm%2];
	}
	return 0;
}
