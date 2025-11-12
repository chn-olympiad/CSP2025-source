#include<bits/stdc++.h>
using namespace std;
int ans=0;
struct node
{
	int a[3],ma;	
}a[100000];
struct node2
{
	int bh,myd;
}b1[110000],b2[110000],b3[110000];
int cmp(node2 x,node2 y)
{
	return x.myd<y.myd;
}
int b11,b22,b33;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			ans=0;
			b11=0;
			b22=0;
			b33=0;
			cin>>a[j].a[0]>>a[j].a[1]>>a[j].a[2];
			if(a[j].a[0]<a[j].a[1])
			{
				a[j].ma=2;
			}else
			{
				a[j].ma=1;
			}
			if(a[j].a[a[j].ma-1]<a[j].a[2])
			{
				a[j].ma=3;
			}
		}
		int c1=0,c2=0,c3=0;
		for(int j=0;j<n;j++)
		{
			if(a[j].ma==1)
			{
				c1++;
			}else if(a[j].ma==2)
			{
				c2++;
			}else
			{
				c3++;
			}
		}
		if(c1>n/2||c2>n/2||c3>n/2)
		{
			for(int j=0;j<n;j++)
			{
				if(a[j].ma==1)
				{
					b1[b11].bh=j;
					b1[b11].myd=a[j].a[a[j].ma-1];
					b11++; 
				}else if(a[j].ma==2)
				{
					b2[b22].bh=j;
					b2[b22].myd=a[j].a[a[j].ma-1];
					b22++;
				}else
				{
					b3[b33].bh=j;
					b3[b33].myd=a[j].a[a[j].ma-1];
					b33++;
				}
			}
			c1=b11-(n/2);
			c2=b22-(n/2);
			c3=b33-(n/2);
			if(c1>0)
			{
				sort(b1,b1+b11,cmp);
				for(int j=0;j<c1;j++)
				{
					if(a[b1[j].bh].a[1]>a[b1[j].bh].a[2])
					{
						b2[b22].bh=b1[j].bh;
						b2[b22].myd=a[b1[j].bh].a[1];
						b22++;
						b1[j].myd=0;
					}else
					{
						b3[b33].bh=b1[j].bh;
						b3[b33].myd=a[b1[j].bh].a[2];
						b33++;
						b1[j].myd=0;
					}
					
				} 
			}else if(c2>0)
			{
				sort(b2,b2+b22,cmp); 
				for(int j=0;j<c2;j++)
				{
					if(a[b2[j].bh].a[0]>a[b2[j].bh].a[2])
					{
						b1[b11].bh=b2[j].bh;
						b1[b11].myd=a[b2[j].bh].a[0];
						b11++;
						b2[j].myd=0;
					}else
					{
						b3[b33].bh=b2[j].bh;
						b3[b33].myd=a[b2[j].bh].a[2];
						b33++;
						b2[j].myd=0;
					}
					
				} 
			}else if(c3>0)
			{
				sort(b3,b3+b33,cmp); 
				for(int j=0;j<c3;j++)
				{
					if(a[b1[j].bh].a[1]>a[b1[j].bh].a[0])
					{
						b2[b22].bh=b3[j].bh;
						b2[b22].myd=a[b3[j].bh].a[1];
						b22++;
						b3[j].myd=0;
					}else
					{
						b1[b11].bh=b1[j].bh;
						b1[b11].myd=a[b3[j].bh].a[0];
						b11++;
						b3[j].myd=0;
					}
					
				} 
			}
			for(int j=0;j<b11;j++)
			{
				ans+=b1[j].myd;
			}
			for(int j=0;j<b22;j++)
			{
				ans+=b2[j].myd;
			}
			for(int j=0;j<b33;j++)
			{
				ans+=b3[j].myd;
			}
		}else
		{
			for(int j=0;j<n;j++)
			{
				ans+=a[j].a[a[j].ma-1];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
