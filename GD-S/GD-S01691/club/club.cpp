#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	for(int I=1;I<=t;I++)
	{
		cin>>n;
		int a1[n+5]={},a2[n+5]={},a3[n+5]={};
		for(int i=1;i<=n;i++) cin>>a1[i]>>a2[i]>>a3[i];
		int ans=0,z1=0,z2=0,z3=0;
		int js[n+5][n+5];
		int sj=n/2;
		js[1][1]=a1[1];
		js[1][2]=a2[1];
		js[1][3]=a3[1];	
		if(js[1][3]<max(js[1][2],js[1][1])&&js[1][3]>min(js[1][2],js[1][1])) z1=1;
		if(js[1][1]<max(js[1][2],js[1][3])&&js[1][1]>min(js[1][2],js[1][3])) z3=1;
		if(js[1][2]<max(js[1][1],js[1][3])&&js[1][2]>min(js[1][1],js[1][3])) z2=1;
		for(int i=2;i<=n;i++)
		{
			if(max(js[i-1][1],js[i-1][2])<js[i-1][3])
			{
				if(z3<sj)
				{
					js[i][1]=a1[i]+js[i-1][3];				
					js[i][2]=a2[i]+js[i-1][3];					
					js[i][3]=a3[i]+js[i-1][3];
					z3++;
				}
				else if(js[i-1][1]>js[i-1][2])
				{
					js[i][1]=a1[i]+js[i-1][1];
					z1++;
					js[i][2]=a2[i]+js[i-1][1];					
					js[i][3]=a3[i]+js[i-1][1];					
				}
				else if(js[i-1][1]==js[i-1][2])
				{
					if(z1<=z2)
					{
						js[i][1]=a1[i]+js[i-1][1];
						z1++;
						js[i][2]=a2[i]+js[i-1][1];						
						js[i][3]=a3[i]+js[i-1][1];					
					}
					else
					{
						js[i][1]=a1[i]+js[i-1][2];					
						js[i][2]=a2[i]+js[i-1][2];
						z2++;
						js[i][3]=a3[i]+js[i-1][2];					
					}
				}
				else
				{
					js[i][1]=a1[i]+js[i-1][2];				
					js[i][2]=a2[i]+js[i-1][2];
					z2++;
					js[i][3]=a3[i]+js[i-1][2];					
				}
			}
			else if(max(js[i-1][3],js[i-1][2])<js[i-1][1])
			{
				if(z1<sj)
				{
					js[i][1]=a1[i]+js[i-1][1];
					z1++;
					js[i][2]=a2[i]+js[i-1][1];					
					js[i][3]=a3[i]+js[i-1][1];				
				}
				else if(js[i-1][3]>js[i-1][2])
				{
					js[i][1]=a1[i]+js[i-1][3];				
					js[i][2]=a2[i]+js[i-1][3];				
					js[i][3]=a3[i]+js[i-1][3];
					z3++;
				}
				else if(js[i-1][3]==js[i-1][2])
				{
					if(z3<=z2)
					{
						js[i][1]=a1[i]+js[i-1][3];					
						js[i][2]=a2[i]+js[i-1][3];					
						js[i][3]=a3[i]+js[i-1][3];
						z3++;
					}
					else
					{
						js[i][1]=a1[i]+js[i-1][2];					
						js[i][2]=a2[i]+js[i-1][2];
						z2++;
						js[i][3]=a3[i]+js[i-1][2];					
					}
				}
				else
				{
					js[i][1]=a1[i]+js[i-1][2];				
					js[i][2]=a2[i]+js[i-1][2];
					z2++;
					js[i][3]=a3[i]+js[i-1][2];				
				}
			}
			else if(max(js[i-1][3],js[i-1][1])<js[i-1][2])
			{
				if(z2<sj)
				{
					js[i][1]=a1[i]+js[i-1][2];				
					js[i][2]=a2[i]+js[i-1][2];
					z2++;
					js[i][3]=a3[i]+js[i-1][2];				
				}
				else if(js[i-1][3]>js[i-1][1])
				{
					js[i][1]=a1[i]+js[i-1][3];				
					js[i][2]=a2[i]+js[i-1][3];				
					js[i][3]=a3[i]+js[i-1][3];
					z3++;
				}
				else if(js[i-1][3]==js[i-1][1])
				{
					if(z3<=z1)
					{
						js[i][1]=a1[i]+js[i-1][3];					
						js[i][2]=a2[i]+js[i-1][3];				
						js[i][3]=a3[i]+js[i-1][3];
						z3++;
					}
					else
					{
						js[i][1]=a1[i]+js[i-1][1];
						z1++;
						js[i][2]=a2[i]+js[i-1][1];					
						js[i][3]=a3[i]+js[i-1][1];					
					}
				}
				else
				{
					js[i][1]=a1[i]+js[i-1][1];
					z1++;
					js[i][2]=a2[i]+js[i-1][1];
					js[i][3]=a3[i]+js[i-1][1];
				
				}
			}
		}
		if(max(js[n][1],js[n][2])<js[n][3]&&z3<=sj)
		{
			cout<<js[n][3]<<endl;
		}
		else if(max(js[n][3],js[n][2])<js[n][1]&&z1<=sj)
		{
			cout<<js[n][1]<<endl;
		}
		else if(max(js[n][3],js[n][1])<js[n][2]&&z2<=sj)
		{
			cout<<js[n][2]<<endl;	
		}
		else if(max(js[n][1],js[n][2])<js[n][3]&&z3>sj)
		{
			if(js[n][1]>js[n][2])
			{
				if(z1<=sj) cout<<js[n][1]<<endl;
			}
			else cout<<js[n][2]<<endl;
		}
		else if(max(js[n][3],js[n][2])<js[n][1]&&z1>sj)
		{
			if(js[n][3]>js[n][2])
			{
				if(z3<=sj) cout<<js[n][3]<<endl;
			}
			else cout<<js[n][2]<<endl;
		}
		else if(max(js[n][3],js[n][1])<js[n][2]&&z2>sj)
		{
			if(js[n][1]>js[n][3])
			{
				if(z1<=sj) cout<<js[n][1]<<endl;
			}
			else cout<<js[n][3]<<endl;	
		}
	}
	return 0;
}
