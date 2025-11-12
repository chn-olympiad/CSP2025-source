#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,ls,ap=0,bp=0,cp=0,sum=0,afull=0,bfull=0,cfull=0,aorigin,borigin,corigin/*,nowc*/;
struct node1
{
	int a,b,c,mark=0,fav;
}pdata[N];

struct node2
{
	int id=-1,point;
}fdp[N/2],sdp[N/2],tdp[N/2];

inline int cmp(node2 x,node2 y)
{
	if(x.point>y.point)
	{
		return 1;
	}
	return 0;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ap=0;
		bp=0;
		cp=0;
		afull=0;
		bfull=0;
		cfull=0;
		aorigin=0;
		borigin=0;
		corigin=0;//清零 
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&pdata[i].a,&pdata[i].b,&pdata[i].c);
			ls=max({pdata[i].a,pdata[i].b,pdata[i].c});
			if(ls==pdata[i].a)//最喜欢部门一 
			{
				pdata[i].fav=1;
				fdp[++ap].id=i;
				fdp[ap].point=pdata[i].a;
			}
			else  if(ls==pdata[i].b)
			{
				pdata[i].fav=2;
				sdp[++bp].id=i;
				sdp[bp].point=pdata[i].b;
			}
			else
			{
				pdata[i].fav=3;
				tdp[++cp].id=i;
				tdp[cp].point=pdata[i].c;
			}
		}
		//nowc=1;
		sort(fdp+1,fdp+ap+1,cmp);
		for(int i=1;i<=n/2;i++)//分配第一部门的人 
		{
			if(fdp[i].id==-1)//分配完所有最喜欢一号部门的人
			{
				break;
			}
			pdata[fdp[i].id].mark=1;
			sum+=fdp[i].point;
			aorigin=i;
			if(i==n/2)//部门满了 
			{
				afull=1;
			}
		}
		//nowc=2;
		sort(sdp+1,sdp+bp+1,cmp);
		for(int i=1;i<=n/2;i++)//分配第二部门的人 
		{
			if(sdp[i].id==-1)//分配完所有最喜欢二号部门的人 
			{
				break;
			}
			pdata[sdp[i].id].mark=1;
			sum+=sdp[i].point;
			borigin=i;
			if(i==n/2)//部门满了
			{
				bfull=1;
			}
		}
		//nowc=3;
		sort(tdp+1,tdp+cp+1,cmp);
		for(int i=1;i<=n/2;i++)//分配第三部门的人 
		{
			if(tdp[i].id==-1)//分配完所有最喜欢三号部门的人
			{
				break;
			}
			pdata[tdp[i].id].mark=1;
			sum+=tdp[i].point;
			corigin=i;
			if(i==n/2)//部门满了
			{
				cfull=1;
			}
		}
		for(int i=1;i<=n;i++)//记录下剩余的那些无法满足最喜欢的部门的人，把他们次喜欢的进行记录 
		{
			if(!pdata[i].mark)
			{
				switch(pdata[i].fav)
				{
					case 1:
						{
							if(pdata[i].b>=pdata[i].c)
							{
								sdp[++bp].id=i;
								sdp[bp].point=pdata[i].b;
							}
							else
							{
								tdp[++cp].id=i;
								tdp[cp].point=pdata[i].c;
							}
							break;
						}
					case 2:
						{
							if(pdata[i].a>=pdata[i].c)
							{
								sdp[++ap].id=i;
								sdp[ap].point=pdata[i].a;
							}
							else
							{
								tdp[++cp].id=i;
								tdp[cp].point=pdata[i].c;
							}
							break;
						}
					default:
						{
							if(pdata[i].a>=pdata[i].b)
							{
								sdp[++ap].id=i;
								sdp[ap].point=pdata[i].a;
							}
							else
							{
								tdp[++bp].id=i;
								tdp[bp].point=pdata[i].b;
							}
							break;
						}
				}
			}
		}
		if(afull)//一号部门满了 
		{
			//nowc=2;
			sort(sdp+borigin,sdp+bp+1,cmp);
			for(int i=borigin+1;i<=n/2;i++)//安排二号部门 
			{
				if(sdp[i].id==-1)
				{
					break;
				}
				pdata[sdp[i].id].mark=1;
				sum+=sdp[i].point;
				if(i==n/2)
				{
					bfull=1;
				}
			}
			//nowc=3;
			sort(tdp+corigin,tdp+cp+1,cmp);
			for(int i=corigin+1;i<=n/2;i++)//安排三号部门 
			{
				if(tdp[i].id==-1)
				{
					break;
				}
				pdata[tdp[i].id].mark=1;
				sum+=tdp[i].point;
				if(i==n/2)
				{
					cfull=1;
				}
			}
		}
		else  if(bfull)//二号部门满了 
		{
			//nowc=1;
			sort(fdp+aorigin,fdp+ap+1,cmp);
			for(int i=aorigin+1;i<=n/2;i++)//安排一号部门 
			{
				if(fdp[i].id==-1)
				{
					break;
				}
				pdata[fdp[i].id].mark=1;
				sum+=fdp[i].point;
				if(i==n/2)
				{
					afull=1;
				}
			}
			//nowc=3;
			sort(tdp+corigin,tdp+cp+1,cmp);
			for(int i=corigin+1;i<=n/2;i++)//安排三号部门 
			{
				if(tdp[i].id==-1)
				{
					break;
				}
				pdata[tdp[i].id].mark=1;
				sum+=tdp[i].point;
				if(i==n/2)
				{
					cfull=1;
				}
			}
		}
		else//三号部门满了 
		{
			//nowc=1;
			sort(fdp+aorigin,fdp+ap+1,cmp);
			for(int i=aorigin+1;i<=n/2;i++)//安排一号部门 
			{
				if(fdp[i].id==-1)
				{
					break;
				}
				pdata[fdp[i].id].mark=1;
				sum+=fdp[i].point;
				if(i==n/2)
				{
					afull=1;
				}
			}
			//nowc=2;
			sort(sdp+borigin,sdp+bp+1,cmp);
			for(int i=borigin+1;i<=n/2;i++)//安排二号部门 
			{
				if(sdp[i].id==-1)
				{
					break;
				}
				pdata[sdp[i].id].mark=1;
				sum+=sdp[i].point;
				if(i==n/2)
				{
					bfull=1;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
