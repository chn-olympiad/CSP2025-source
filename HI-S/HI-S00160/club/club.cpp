#include<bits/stdc++.h>
using namespace std;
int t;
int n,a[100010][3],ats[101000];
int ab[100100],ac[100001],bc[100100];
int bb=0,cc=0;
int ans=0;
bool cmp(int x,int y)
{
	if(x>y)
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
	for(int k=1;k<=t;k++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0)
			{
				bb=1;
			}
			if(a[i][3]!=0)
			{
				cc=1;
			}
		}
		if(bb==0&&cc==0)
		{
			for(int i=1;i<=n;i++)
			{
				ats[i]=a[i][1];
				
			}
			
			sort(ats+1,ats+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans=ans+ats[i];
				
			}
			printf("%d\n",ans);
			continue;
		
		}
		if(cc==0&&bb!=0)
		{
			int zdz=0;//最大值 
			int s1=0,s2=0;//分别有几个最大值
			int bh=0;//有几个数要换走 
			for(int i=1;i<=n;i++)
			{
				ab[i]=a[i][1]-a[i][2];
				if(ab[i]<0)
				{
					ab[i]=-1*ab[i];
				}
				if(a[i][1]>=a[i][2])
				{
					zdz=zdz+a[i][1];
					s1++;
				}
				else
				{
					zdz=zdz+a[i][2];
					s2++;
				}
			}
			int pp=0;
			if(s1<s2)
			{
				for(int i=1;i<=n;i++)
				{
					if(a[i][1]>a[i][2])
					{
						ab[i]=-1;
						pp++;
					}
				 } 
			} 
			sort(ab+1,ab+n+1);
		/*	for(int i=1;i<=n;i++)
			{
				cout<<ab[i]<<" ";
			}*/
		//	cout<<endl<<zdz<<endl;
		
			if(s1>s2&&s1>n/2)
			{
				bh=s1-n/2;
				
				for(int j=pp+1;j<=bh+pp;j++)
				{
					zdz=zdz-ab[j];
					printf("%d\n",zdz);
				}
			} 
			if(s1>s2&&s1<=n/2)
			{
				printf("%d\n",zdz);
			} 
			if(s2>s1&&s2>n/2)
			{
				bh=s2-n/2;
				for(int j=pp+1;j<=bh+pp;j++)
				{
					zdz=zdz-ab[j];
					printf("%d\n",zdz);
				}
			} 
			if(s2>=s1&&s2<=n/2)
			{
				printf("%d\n",zdz);
			}  
			continue;
		}	
	
		
		if(n==2&&bb!=0&&cc!=0)
		{
			int mm=0;
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(i!=j)
					{
						mm=max(mm,a[1][i]+a[2][j]);
					}
				}
			
			}
			printf("%d\n",mm);
			continue;
		}
		
		
	}
	return 0;
}

