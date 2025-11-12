#include<bits/stdc++.h>
using namespace std;
int a[100010][10];
int b[100010];
int c[100010];
int mp1[10];
int mp2[10]; 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	cin>>t;
	for(;t>0;t--)
	{
		memset(a,0,sizeof(a));
		int n=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		int mm=0;
		//dezuida
		for(int i=1;i<n;i++)
		{
			int q=0,q1=0;
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]>q)
				{
					q=a[i][j];
					q1=j;
				}
			}
			mp1[q1]++;
		}
		if(mp1[1]>=n/2)//panduanjinzheng1
		{
			//比较 
			for(int i=1;i<=n;i++)
			{
				if(a[i][2]>a[i][3])
				{
					b[i]=a[i][1]-a[i][2];
				}
				else
				{
					b[i]=a[i][1]-a[i][3];
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<n;j++)
				{
					if(b[j]<b[j+1])
					{
						swap(a[j][1],a[j+1][1]);
						swap(a[j][2],a[j+1][2]);
						swap(a[j][3],a[j+1][3]);
						swap(b[j],b[j+1]);
					}
				}	
			}
			//去
			for(int i=1;i<=n/2;i++)
			{
				mm+=a[i][1];
				a[i][1]=-1;
				a[i][2]=-1;
				a[i][3]=-1;
			}
			//去2
			for(int i=1;i<=n;i++)
			{
				if(a[i][2]>a[i][3]&&a[i][1]!=-1)
				{
					mm+=a[i][2];
					a[i][1]=-1;
					a[i][2]=-1;
					a[i][3]=-1;
				}
				else if(a[i][1]!=-1)
				{
					mm+=a[i][3];
					a[i][1]=-1;
					a[i][2]=-1;
					a[i][3]=-1;
				}
			}
		}
		else//第一无竞争
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])
				{
					mm+=a[i][1];
					a[i][1]=-1;
					a[i][2]=-1;
					a[i][3]=-1;
				}
			}
			if(mp1[1]>n/2)//panduanjinzheng2
			{
				//比较 
				for(int i=1;i<=n;i++)
				{
					b[i]=a[i][2]-a[i][3];
				}
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<n;j++)
					{
						if(b[j]<b[j+1])
						{
							swap(a[j][1],a[j+1][1]);
							swap(a[j][2],a[j+1][2]);
							swap(a[j][3],a[j+1][3]);
							swap(b[j],b[j+1]);
						}
					}	
				}
				//去
				for(int i=1;i<=n/2;i++)
				{
					mm+=a[i][1];
					a[i][1]=-1;
					a[i][2]=-1;
					a[i][3]=-1;
				}
				//去2
				for(int i=1;i<=n;i++)
				{
					if(a[i][1]!=-1)
					{
						mm+=a[i][3];
					}
				}
			}
		}
		cout<<mm<<endl;
	}
	return 0;
}

