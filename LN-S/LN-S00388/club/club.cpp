#include<bits/stdc++.h>
using namespace std;
int cus[10];
struct ren
{
	int manyi11;
	int manyi22;
	int manyi33;
	int cha12;
	int cha23;
}r[100100];
bool cmp(ren x,ren y)
{
	return x.cha12>=y.cha12;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//Ren5Jie4Di4Ling5%
	//whw
	int t,e=0;
	scanf("%d",&t);
	for(int z=1;z<=t;z++)
	{
		for(int i=1;i<=e;i++)
		{
			r[i].cha12=0;
			r[i].cha23=0;
			r[i].manyi11=0;
			r[i].manyi22=0;
			r[i].manyi33=0;
		}
		int n;
		scanf("%d",&n);
		e=n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&r[i].manyi11,&r[i].manyi22,&r[i].manyi33);
			r[i].cha12=r[i].manyi11-r[i].manyi22;
			r[i].cha23=r[i].manyi22-r[i].manyi33;
		}
		sort(r+1,r+1+n,cmp);
		for(int i=1;i<=(n/2);i++)
		{
			cus[z]+=r[i].manyi11;
		}
		for(int i=(n/2)+1;i<=n;i++)
		{
			cus[z]+=r[i].manyi22;
		}
	}
	for(int z=1;z<=t;z++)
	{
		cout<<cus[z]<<endl;
	}
	return 0;
}
