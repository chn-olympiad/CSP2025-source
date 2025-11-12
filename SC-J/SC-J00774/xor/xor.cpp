#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}qj[500010];
int n,k,a[500010],cnt,zuidazhi=-1,zxz,tot,hp[500010];
bool lxe(node aa,node bb)
{
	return aa.l<bb.l;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(j==i&&a[j]==k)
			{
				cnt++;
				qj[cnt].l=i;
				qj[cnt].r=i;
			}
			else
			{
				int p=a[i];
				for(int v=i+1;v<=j;v++)
				{
					p=(p^a[v]);
				}
				if(p==k)
				{
					cnt++;
					qj[cnt].l=i;
					qj[cnt].r=j;
				}
			}
		}
	}
	
	sort(qj+1,qj+1+cnt,lxe);
	for(int i=1;i<=cnt;i++)
	{
		if(qj[i].r-qj[i].l!=qj[i-1].l)
		{
			zxz=qj[i].r-qj[i].l;
			tot++;
			hp[tot]=i;
			continue;	
		}
		if(qj[i].r-qj[i].l<zxz)
		{
			zxz=qj[i].r-qj[i].l;
			tot++;
			hp[tot]=i;
		}
	}
	for(int i=1;i<=tot-1;i++)
	{
		int zjie=qj[i].r,bjs=1;
		for(int j=i+1;j<=tot;j++)
		{
			if(qj[j].l>zjie)
			{
				bjs++;
				zjie=qj[j].r;
			}
		}
		zuidazhi=max(zuidazhi,bjs);
	}
	cout<<zuidazhi;
	return 0;
}