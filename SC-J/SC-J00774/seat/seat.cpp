#include<bits/stdc++.h>
using namespace std;
int n,m,haomashu;
struct node{
	int xueshengchengji,xueshenghao;
}v[110];
bool lxe(node b,node c)
{
	return b.xueshengchengji>c.xueshengchengji;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>v[i].xueshengchengji;
		v[i].xueshenghao=i;
	}
	sort(v+1,v+1+n*m,lxe);
	for(int i=1;i<=m;i++)
	{
		if(i%2)
		{
			for(int j=1;j<=n;j++)
			{
				haomashu++;
				if(v[haomashu].xueshenghao==1)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				haomashu++;
				if(v[haomashu].xueshenghao==1)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}