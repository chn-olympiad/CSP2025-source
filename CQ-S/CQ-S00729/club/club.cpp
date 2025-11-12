#include<iostream>
#include<algorithm>
using namespace std;
int n,t,df[5],rr[100086];
long long sum,maxx,d[100086][3];
void nosearchnofirstprize(int ig)
{
	for(int i=0;i<3;i++)
	{
		if(df[i]>n/2)
		{
			return;		
		}
	}
	if(ig>n)
	{
		sum=0;
		for(int i=0;i<3;i++) df[i]=0;
		//for(int i=1;i<=n;i++)
		//{
		//	cout<<rr[i]<<' '; 
		//}
		//cout<<endl;
		//if(rr[1]==0&&rr[2]==0&&rr[3]==1&&rr[4]==1)
		//{
		//	cout<<d[1][0]<<d[2][0]<<d[3][1]<<d[4][1]<<endl;
		//}
		for(int i=1;i<=n;i++)
		{
			df[rr[i]]++;
			sum+=d[i][rr[i]];
		}
		/*for(int i=0;i<3;i++)
		{
			//cout<<df[i]<<' ';
			if(df[i]>n/2)
			{
				sum=0;		
			}
		}*/
		//cout<<endl<<sum<<endl; 
		maxx=max(sum,maxx);
		return;
	}
	for(int i=0;i<3;i++)
	{
		rr[ig]=i;
		df[i]++;
		nosearchnofirstprize(ig+1);
		df[rr[ig]]=0;
		//rr[ig]=0;
	}
}
void nosearchnofirstprize2(int ig)
{
	for(int i=0;i<2;i++)
	{
		if(df[i]>n/2)
		{
			return;		
		}
	}
	if(ig>n)
	{
		sum=0;
		for(int i=0;i<2;i++) df[i]=0;
		for(int i=1;i<=n;i++)
		{
			df[rr[i]]++;
			sum+=d[i][rr[i]];
		}
		maxx=max(sum,maxx);
		return;
	}
	for(int i=0;i<2;i++)
	{
		rr[ig]=i;
		df[i]++;
		nosearchnofirstprize(ig+1);
		df[rr[ig]]=0;
	}
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==4)
		{
			for(int i=1,cl;i<=n;i++) cin>>cl>>rr[i]>>cl;
			sort(rr+1,rr+n+1);
			for(int i=n;i>=n/2;i--)
			{
				cout<<rr[i]<<' ';
				sum+=rr[i];
			}
			cout<<sum;
			return 0;
		}		
		for(int i=1;i<=n;i++)
		{
			cin>>d[i][0]>>d[i][1]>>d[i][2];	
		}
		
		if(n==2)
		{
			maxx=0;
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					if(i!=j)
					{
						maxx=max(d[1][i]+d[2][j],maxx);
					}
				}
			}
			cout<<maxx<<endl;
		}
		else if(n==4)
		{
			maxx=0;//ijk ijl ikl jkl 
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					for(int k=0;k<3;k++)
					{
						for(int l=0;l<3;l++)
						{
							if(!(i==j&&i==k||i==j&&i==l||i==k&&i==l||j==k&&k==l))
							{
								maxx=max(d[1][i]+d[2][j]+d[3][k]+d[4][l],maxx);
							}
						}
					}
				}
			}
			cout<<maxx<<endl; 
		}
		else if(n<=10)
		{
			sum=df[0]=df[1]=df[2]=maxx=0;
			for(int i=1;i<=n;i++) rr[i]=0;
			nosearchnofirstprize(1);
			cout<<maxx<<endl;
		}
		else if(n<=200)
		{
			sum=df[0]=df[1]=maxx=0;
			for(int i=1;i<=n;i++) rr[i]=0;
			nosearchnofirstprize2(1);
			cout<<maxx<<endl;			
		}
	}
	return 0;
} 
/*






*/
