#include<bits/stdc++.h> 
using namespace std;

struct stdent
{
	int id,a,b,c;
	bool beinto=0;
}names[100010],ba[50005],bb[50005],bc[50005];

void saming(int a)
{
	bool posa=1,posb=1,posc=1;
	for(int i=1;i<=sizeof(ba)/17;i++)
	{
		if(ba[i].id==a && posa)
		{
			ba[i].beinto=1;
			posa=0;
		}
		if(bb[i].id==a && posb)
		{
			bb[i].beinto=1;
			posa=0;
		}
		if(bc[i].id==a && posc)
		{
			bc[i].beinto=1;
			posa=0;
		}
	}
}


int fucn()
{
	int n,cnt=0;
	cin>>n;
	bool f1=0,f2=0,f3=0;
	
	for(int j=1;j<=n;j++)
	{
		names[j].id=j;
		cin>>names[j].a>>names[j].b>>names[j].c;
		int k=1;
		while(1)
		{
			if(ba[k].a<names[j].a && !f1)
			{
				f1=1;
				for(int l=j;l>=k;l--)
				{
					ba[l-1]=ba[l];
				}
			}
			if(bb[k].b<names[j].b && !f2)
			{
				f2=1;
				for(int l=j;l>=k;l--)
				{
					bb[l-1]=bb[l];
				}
			}
			if(bc[k].c<names[j].c && !f3)
			{
				f3=1;
				for(int l=j;l>=k;l--)
				{
					bc[l-1]=bc[l];
				}
			}
			if(f1 && f2 && f3)
				break;
		}
	}
	f1=0;
	f2=0;
	f3=0;
	int cnta=0,cntb=0,cntc=0;
	for(int j=1;j<=n/2;j++)
	{
		if(ba[j].id!=bb[j].id && ba[j].id!=bc[j].id && bc[j].id!=bb[j].id)//3繁 abc
		{
			if(ba[j].beinto)
			{
				if(bb[j].beinto)//複c 
				{
					if(bc[j].beinto)//音複
					{
						continue;
					}
					cntc++;
					cnt+=bc[j].c;
					saming(bc[j].id);
				}	
				if(bc[j].beinto)//複b
				{
					cntb++;
					cnt+=bb[j].b;
					saming(bb[j].id);
				}
				//複bc
				cntb++;
				cntc++;
				cnt+=bc[j].c;
				saming(bc[j].id);
				cnt+=bb[j].b;
				saming(bb[j].id);
			}
			else
			{
				if(bb[j].beinto)
				{
					if(bc[j].beinto)//複a
					{
						cnta++;
						cnt+=ba[j].a;
						saming(ba[j].id);
					}
					//複ac
					cnta++;
					cntc++;
					cnt+=ba[j].a;
					saming(ba[j].id);
					cnt+=bc[j].c;
					saming(bc[j].id);
				}
				if(bc[j].beinto)//複ab
				{
					cnta++;
					cntb++;
					cnt+=ba[j].a;
					saming(ba[j].id);
					cnt+=bb[j].b;
					saming(bb[j].id);
				}
			}
			//複abc
			cnta++;
			cntb++;
			cntc++;
			cnt+=ba[j].a;
			saming(ba[j].id);
			cnt+=bb[j].b;
			saming(bb[j].id);
			cnt+=bc[j].c;
			saming(bc[j].id);
		}
		else if(ba[j].id==bb[j].id && ba[j].id==bc[j].id && bc[j].id==bb[j].id)//1繁 a
		{
			if(bc[j].beinto)//音複
			{
				continue;
			}
			//複a 
			cnta++;
			cnt+=ba[j].a;
			saming(ba[j].id);
		}
		else
		{
			if(ba[j].id==bb[j].id && ba[j].id!=bc[j].id)//2繁 ac 
			{
				if(ba[j].beinto)
				{
					if(bc[j].beinto)//音複
					{
						continue;
					}
					//複c
					cntc++;
					cnt+=bc[j].c;
					saming(bc[j].id);
				}
				else
				{
					if(bc[j].beinto)//複a
					{
						cnta++;
						cnt+=ba[j].a;
						saming(ba[j].id);
					}
					//複ac
					cnta++;
					cntc++;
					cnt+=ba[j].a;
					saming(ba[j].id);
					cnt+=bc[j].c;
					saming(bc[j].id);
				}
			}
			else if(ba[j].id!=bb[j].id && ba[j].id==bc[j].id)//2繁 ab
			{
				if(ba[j].beinto)
				{
					if(bb[j].beinto)//音複
					{
						continue;
					}
					//複b
					cntb++;
					cnt+=bb[j].b;
					saming(bb[j].id);
				}
				else
				{
					if(bb[j].beinto)//複a
					{
						cnta++;
						cnt+=ba[j].a;
						saming(ba[j].id);
					}
					//複ab
					cnta++;
					cntb++;
					cnt+=ba[j].a;
					saming(ba[j].id);
					cnt+=bb[j].b;
					saming(bb[j].id);
				}
			}
			else//2繁 bc
			{
				if(bb[j].beinto)
				{
					if(bc[j].beinto)//音複
					{
						continue;
					}
					//複c
					cntc++;
					cnt+=bc[j].c;
					saming(bc[j].id);
				}
				else
				{
					if(bc[j].beinto)//複b
					{
						cntb++;
						cnt+=bb[j].b;
						saming(bb[j].id);
					}
					//複bc
					cntb++;
					cntc++;
					cnt+=bb[j].b;
					saming(bb[j].id);
					cnt+=bc[j].c;
					saming(bc[j].id);
				}
			}
		}
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,ans[15];
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		ans[i]=fucn();
	}
	for(int i=1;i<=t;i++)
	{
		cout<<ans[i];
	}
	return 0;
}
