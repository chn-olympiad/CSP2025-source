#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long t;
long long n;
long long ans=0;

long long will[3]={0};


struct node
{
	long long maxn;
	int fm;
	long long past;
}lis[100000+5];
node lpast[100000+5]={-1,-1,100000};

struct into
{
	int part;
	long long val;
};

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		ans=0;
		will[0]=0;
		will[1]=0;
		will[2]=0;
		
		cin>>n;
		
		into a[3];
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=2;j++)
			{
				a[j].part=j;
				cin>>a[j].val;
			} 
		
			into temp={-1,0};
			for(int j=0;j<=2;j++)
			{
				if(a[j].val>temp.val)
				{
					temp=a[j];
				}
			}
			lis[i].fm=temp.part;
			lis[i].maxn=temp.val;
			will[temp.part]++;
			
			temp={-1,0};
			for(int j=0;j<=2;j++)
			{
				if(a[j].val>temp.val&&a[j].val!=lis[i].maxn)
				{
					temp=a[j];
				}
			}
			lis[i].past=lis[i].maxn-temp.val;//排序处理结束 
		}
		
		
		for(int i=0;i<=2;i++)
		{
			if(will[i]<=(n/2))
			{
				for(int j=1;j<=n;j++)
				{
					if(lis[j].fm==i)//这个人最大意愿来i号部门
					{
						ans+=lis[j].maxn;
						
						lis[j].maxn=0;
						lis[j].fm=-1;
						lis[j].past=0;
					} 
				}
					
			}
			else
			{
				int lpastsize=0;
				for(int j=1;j<=n;j++)
				{
					if(lis[j].fm==i)//这个人最大意愿来i号部门
					{
						int x=0;
						while(lpast[x].past<=lis[j].past)//从小到大排序past
						{
							x++;
						}
						
						long long xt=lpastsize;
						while(xt>=x)
						{
							lpast[xt+1]=lpast[xt];
							xt--;
						}
						lpast[x]=lis[j];
						
						lpastsize++;
					} 
				}
				
				for(int j=0;j<lpastsize;j++)
				{
					if(j<will[i]-n/2)//更换部门 
					{
						ans+=(lpast[j].maxn-lpast[j].past);
					}
					else//不更换部门 
					{
						ans+=lpast[j].maxn;
					} 
					
				}		
			}
		}
		
		cout<<ans<<endl;
		
		for(int i=0;i<=n;i++)
		{
			lis[i]={0,0,0};
			lpast[i]={-1,-1,100000};
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 }



