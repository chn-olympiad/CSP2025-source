#include <bits/stdc++.h>
using namespace std;
int a[25];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3) cout<<0;
	else if(n==3)
	{
		if(max(a[1],max(a[2],a[3]))*2<a[1]+a[2]+a[3])
		{
			cout<<1;
		}
	}
	else if(n==4)
	{
		if(max(a[1],max(a[2],max(a[3],a[4])))*2<a[1]+a[2]+a[3]+a[4])
		{
			sum++;
		}
		for(int i=1;i<=n;i++)
		{
			int maxx=0,tot=0;
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
					maxx=max(maxx,a[j]);
					tot+=a[j];					
				}
			}
			cout<<maxx<<' '<<tot<<endl;
			if(tot>maxx*2) sum++;
		}	
	}
	else if(n==5)
	{
		if(max(a[1],max(a[2],max(a[3],max(a[4],a[5]))))*2<a[1]+a[2]+a[3]+a[4]+a[5])
		{
			sum++;
		}
		for(int i=1;i<=n;i++)
		{
			int maxx=0,tot=0;
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
					maxx=max(maxx,a[j]);
					tot+=a[j];					
				}
			}

			if(tot!=0&&tot>maxx*2) 	sum++;
		}			
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{	
				for(int k=j+1;k<=n;k++)
				{
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
					{
						sum++;
					}			
				}
			}			
		}			
	}	
	else if(n==6)
	{
		if(max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],a[6])))))*2<a[1]+a[2]+a[3]+a[4]+a[5]+a[6])
		{
			sum++;
		}
		for(int i=1;i<=n;i++)
		{
			int maxx=0,tot=0;
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
					maxx=max(maxx,a[j]);
					tot+=a[j];					
				}
			}

			if(tot!=0&&tot>maxx*2) 	sum++;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{	
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						if(max(a[i],max(a[j],max(a[k],a[l])))*2<a[i]+a[j]+a[k]+a[l])
						{
							sum++;
						}						
					}
		
				}
			}			
		}				
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{	
				for(int k=j+1;k<=n;k++)
				{
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
					{
						sum++;
					}			
				}
			}			
		}				
	}
	else if(n==7)
	{
		if(max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],max(a[6],a[7]))))))*2<a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7])
		{
			sum++;
		}
		for(int i=1;i<=n;i++)
		{
			int maxx=0,tot=0;
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
					maxx=max(maxx,a[j]);
					tot+=a[j];					
				}
			}

			if(tot!=0&&tot>maxx*2) 	sum++;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{	
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						if(max(a[i],max(a[j],max(a[k],a[l])))*2<a[i]+a[j]+a[k]+a[l])
						{
							sum++;
						}						
					}
		
				}
			}			
		}			
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{	
				int maxx=0,tot=0;
				for(int k=1;k<=n;k++)
				{
					if(k!=i&&k!=j)
					{			
						maxx=max(maxx,a[k]);
						tot+=a[k];		
					}						
				}
				if(tot>maxx*2) sum++;
			}			
		}			
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{	
				for(int k=j+1;k<=n;k++)
				{
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
					{
						sum++;
					}			
				}
			}			
		}				
	}
	else if(n==8)
	{
		if(max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],max(a[6],max(a[7],a[8])))))))*2<a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8])
		{
			sum++;
		}
		for(int i=1;i<=n;i++)
		{
			int maxx=0,tot=0;
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
					maxx=max(maxx,a[j]);
					tot+=a[j];					
				}
			}

			if(tot!=0&&tot>maxx*2) 	sum++;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{	
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						if(max(a[i],max(a[j],max(a[k],a[l])))*2<a[i]+a[j]+a[k]+a[l])
						{
							sum++;
						}						
					}
		
				}
			}			
		}			
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{	
				for(int l=j+1;l<=n;l++)
				{
					int maxx=0,tot=0;
					for(int k=1;k<=n;k++)
					{
						if(k!=i&&k!=j&&k!=l)
						{			
							maxx=max(maxx,a[k]);
							tot+=a[k];		
						}						
					}
					if(tot>maxx*2) sum++;				
				}

			}			
		}			
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{	
				for(int k=j+1;k<=n;k++)
				{
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
					{
						sum++;
					}			
				}
			}			
		}				
	}
	else if(n==9)
	{
		if(max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],max(a[6],max(a[7],max(a[8],a[9]))))))))*2<a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9])
		{
			sum++;
		}
		for(int i=1;i<=n;i++)
		{
			int maxx=0,tot=0;
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
					maxx=max(maxx,a[j]);
					tot+=a[j];					
				}
			}

			if(tot!=0&&tot>maxx*2) 	sum++;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{	
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						if(max(a[i],max(a[j],max(a[k],a[l])))*2<a[i]+a[j]+a[k]+a[l])
						{
							sum++;
						}						
					}
		
				}
			}			
		}			
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{	
				for(int l=j+1;l<=n;l++)
				{
					int maxx=0,tot=0;
					for(int k=1;k<=n;k++)
					{
						if(k!=i&&k!=j&&k!=l)
						{			
							maxx=max(maxx,a[k]);
							tot+=a[k];		
						}						
					}
					if(tot>maxx*2) sum++;				
				}

			}			
		}			
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{	
				for(int l=j+1;l<=n;l++)
				{
					for(int m=l+1;m<=n;m++)
					{
						int maxx=0,tot=0;
						for(int k=1;k<=n;k++)
						{
							if(k!=i&&k!=j&&k!=l&&k!=m)
							{			
								maxx=max(maxx,a[k]);
								tot+=a[k];		
							}						
						}	
						if(tot>maxx*2) sum++;	
					}			
				}

			}			
		}	
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{	
				for(int k=j+1;k<=n;k++)
				{
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
					{
						sum++;
					}			
				}
			}			
		}				
	}
	else if(n==10)
	{
		if(max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],max(a[6],max(a[7],max(a[8],max(a[9],a[10])))))))))*2<a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10])
		{
			sum++;
		}
		for(int i=1;i<=n;i++)
		{
			int maxx=0,tot=0;
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
					maxx=max(maxx,a[j]);
					tot+=a[j];					
				}
			}

			if(tot!=0&&tot>maxx*2) 	sum++;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{	
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						if(max(a[i],max(a[j],max(a[k],a[l])))*2<a[i]+a[j]+a[k]+a[l])
						{
							sum++;
						}						
					}
		
				}
			}			
		}			
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{	
				for(int l=j+1;l<=n;l++)
				{
					int maxx=0,tot=0;
					for(int k=1;k<=n;k++)
					{
						if(k!=i&&k!=j&&k!=l)
						{			
							maxx=max(maxx,a[k]);
							tot+=a[k];		
						}						
					}
					if(tot>maxx*2) sum++;				
				}

			}			
		}			
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{	
				for(int l=j+1;l<=n;l++)
				{
					for(int m=l+1;m<=n;m++)
					{
						int maxx=0,tot=0;
						for(int k=1;k<=n;k++)
						{
							if(k!=i&&k!=j&&k!=l&&k!=m)
							{			
								maxx=max(maxx,a[k]);
								tot+=a[k];		
							}						
						}	
						if(tot>maxx*2) sum++;	
					}			
				}

			}			
		}	
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{	
				for(int k=j+1;k<=n;k++)
				{
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
					{
						sum++;
					}			
				}
			}			
		}		
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{	
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						for(int m=l+1;m<=n;m++)
						{
							if(max(a[i],max(a[j],max(a[k],max(a[l],a[m]))))*2<a[i]+a[j]+a[k]+a[l]+a[m])
							{
								sum++;
							}	
						}					
					}
		
				}
			}			
		}			
	}
	cout<<sum;
	return 0;
}
