#include<bits/stdc++.h> 
using namespace std;
struct d
{
	int a,b,c,da,xiao,xi;
}e[100005];
int cmp1(int a,int b)
{
	
	return e[a].a-e[a].xi<e[b].a-e[b].xi;
}
int cmp2(int a,int b)
{
	
	return e[a].b-e[a].xi<e[b].b-e[b].xi;
}
int cmp3(int a,int b)
{
	
	return e[a].c-e[a].xi<e[b].c-e[b].xi;
}
int aaa[100005],bbb[100005],ccc[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t)
	{
		int n,aa=0,bb=0,cc=0,sum=0;
		cin>>n;
		for(int i = 1;i<=n;i++)
		{
			cin>>e[i].a>>e[i].b>>e[i].c;
			if(e[i].a>e[i].b)
			{
				if(e[i].a>e[i].c)
				{
					aa++;
					aaa[aa]=i;
					if(e[i].c>e[i].b)
					{
						e[i].xiao=3;	
						e[i].xi=e[i].c;
					}
					else
					{
						e[i].xiao=2;
						e[i].xi=e[i].b;	
					}
				}
				else
				{
					cc++;
					ccc[cc]=i;
					e[i].xiao=1;
					e[i].xi=e[i].a;
					
				}
			}
			else
			{
				if(e[i].b>e[i].c)
				{
					bb++;
					bbb[bb]=i;
					if(e[i].c>e[i].a)
					{
						e[i].xiao=3;
						e[i].xi=e[i].c;	
					}
					else
					{
						e[i].xiao=1;	
						e[i].xi=e[i].a;
					}
					
				}
				else
				{
					cc++;
					ccc[cc]=i;
					e[i].xiao=2;
					e[i].xi=e[i].b;
				}	
			}
		}
		if(aa>n/2)
		{
			sort(aaa+1,aaa+aa+1,cmp1);
			for(int i = 1;i<=aa-n/2;i++)
			{
				sum+=e[aaa[i]].xi;
				
			}
			for(int i = aa-n/2;i<=aa;i++)
			{
				sum+=e[aaa[i]].a;
				
			}
			for(int i = 1;i<=bb;i++)
			{
				sum+=e[bbb[i]].b;
			}
			for(int i = 1;i<=cc;i++)
			{
				sum+=e[ccc[i]].c;
			}
		}
		else if(bb>n/2)
		{
			sort(bbb+1,bbb+bb+1,cmp2);
			for(int i = 1;i<=bb-n/2;i++)
			{
				sum+=e[bbb[i]].xi;
				
			}
			for(int i = bb-n/2;i<=bb;i++)
			{
				sum+=e[bbb[i]].b;
				
			}
			for(int i = 1;i<=aa;i++)
			{
				sum+=e[aaa[i]].a;
			}
			for(int i = 1;i<=cc;i++)
			{
				sum+=e[ccc[i]].c;
			}
		}
		else if(cc>n/2)
		{
			sort(ccc+1,ccc+cc+1,cmp3);
			for(int i = 1;i<=cc-n/2;i++)
			{
				sum+=e[ccc[i]].xi;
				
			}
			for(int i = cc-n/2;i<=cc;i++)
			{
				sum+=e[ccc[i]].c;
				
			}
			for(int i = 1;i<=bb;i++)
			{
				sum+=e[bbb[i]].b;
			}
			for(int i = 1;i<=aa;i++)
			{
				sum+=e[aaa[i]].a;
			}
		}
		else
		{
			for(int i = 1;i<=bb;i++)
			{
				sum+=e[bbb[i]].b;
			}
			for(int i = 1;i<=aa;i++)
			{
				sum+=e[aaa[i]].a;
			}
			for(int i = 1;i<=cc;i++)
			{
				sum+=e[ccc[i]].c;
			}
		}
		cout<<sum<<endl;
		t--;
	}
	return 0;
}
