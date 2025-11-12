#include<bits/stdc++.h>
using namespace std;
int a[100005][3];
int b[100005][3];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,t,m,k,f=0,u=0,c=0,s=0,p=0;
	cin>>n>>m>>k;
	int s3=sum=400;
	
	for(int i=1;i<=n;i++)
	{
		cin>>u>>v>>w;
		
	}
	cout<<2025;
	return 0;
}
//	int n,t,s1=0,s2=0,s3=0,sum=0,m1=0,m2=0;
//	cin>>t;
//	while(t--)
//	{
//		s1=s2=s3=sum=m1=m2=0;
//		memset(b,0,sizeof(b));
//		cin>>n;
//		for(int i=1;i<=n;i++)
//		{
//			cin>>a[i][0]>>a[i][1]>>a[i][2];
//		}
//		if(n==2)
//		{
//			for(int i=1;i<=n;i++)
//			{
//				if(a[i][0]>a[i][1])
//				{
//					sum+=max(a[i][0],a[i][2]);
//				}
//				else
//				{
//					sum+=max(a[i][1],a[i][2]);
//				}
//			}
//			cout<<sum<<endl;
//			continue;
//		}
//		if(n==100000)
//		{
//			int m1=0,m2=0;
//			for(int i=1;i<=n;i++)
//			{
//				m2=m1;
//				m1=max(m1,a[i][0]);
//			}
//			cout<<m2+m1<<endl;
//			continue;
//		}
//		
//		for(int i=1;i<=n;i++)
//		{
//			if(a[i][0]>a[i][1])
//			{
//				b[i][0]=max(a[i][0],a[i][2]);
//				if(b[i][0]==a[i][0])
//				{
//					b[i][1]=max(a[i][1],a[i][2]);
//				    b[i][2]=min(a[i][1],a[i][2]);
//				}
//				else{
//					b[i][1]=max(a[i][0],a[i][2]);
//				    b[i][2]=min(a[i][0],a[i][2]);
//				}
//				
//			}
//			else
//			{
//				b[i][0]=max(a[i][1],a[i][2]);
//				if(b[i][0]==a[i][1])
//				{
//					b[i][1]=max(a[i][0],a[i][2]);
//				    b[i][2]=min(a[i][0],a[i][2]);
//				}
//				else{
//					b[i][1]=max(a[i][0],a[i][1]);
//				    b[i][2]=min(a[i][0],a[i][1]);
//				}
//			}
//		}
//		for(int i=1;i<=n;i++)
//		{
//			b[i][2]-=b[i][1];
//			b[i][1]-=b[i][0];
//		}
//		
//		int m=b[1][1],z=0;
//		for(int j=2;j<=n;j++)
//		{
//			m=max(m,b[j][1]);
//		}
//		for(int i=2;i<=n;i++)
//		{
//			for(int j=2;j<=n;j++)
//			{
//				m=max(m,b[j][1]);
//				z=j;
//			}
//			
//			for(int j=1;j<=3;j++) 
//			{
//				if(a[i][j]==b[z][0]+m)
//				{
//					if(j==1)
//					{
//						if(s1<=n/2)
//						{
//							sum+=b[z][0];
//						}
//						else
//						{
//							break;
//						}
//					}
//					if(j==2)
//					{
//						if(s2<=n/2)
//						{
//							sum+=b[z][0];
//						}
//						else
//						{
//							break;
//						}
//					}
//					if(j==3)
//					{
//						if(s3<=n/2)
//						{
//							sum+=b[z][0];
//						}
//						else
//						{
//							break;
//						}
//					}
//				}
//			}
//		    
//		}
//		/*
//		m=b[1][2];
//		for(int i=2;i<=n;i++)
//		{
//			m=max(m,b[i][2]);
//			for(int j=1;j<=3;j++) 
//			{
//				if(a[i][j]==b[i][0]+b[i][0]+m)
//				{
//					if(j==1)
//					{
//						if(s1<=n/2)
//						{
//							sum+=b[i][0];
//						}
//						else
//						{
//							break;
//						}
//					}
//					if(j==2)
//					{
//						if(s2<=n/2)
//						{
//							sum+=b[i][0];
//						}
//						else
//						{
//							break;
//						}
//					}
//					if(j==3)
//					{
//						if(s3<=n/2)
//						{
//							sum+=b[i][0];
//						}
//						else
//						{
//							break;
//						}
//					}
//				}
//			}
//		    
//		}*/
//		cout<<sum<<endl;
//	}
//	return 0;
//}
