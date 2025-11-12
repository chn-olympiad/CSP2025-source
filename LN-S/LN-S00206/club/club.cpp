#include<bits/stdc++.h>
using namespace std;
int a[10005][5], num[10005], aa1[10005], aa2[10005], aa3[10005], za[10005][5], qw;
int fl=1;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n=0, t=0, ans=0, d1=0, d2=0, d3=0, t1[20010], c=0,v=0, maxx=0;
	cin>>t;
	for(int iii=1;iii<=t;iii++)
	{
		memset(a,0,sizeof(a));
		n=0;
		ans=0;
		d1=0; d2=0; d3=0;
		memset(num,0,sizeof(num));
		memset(aa1,0,sizeof(aa1));
		memset(aa2,0,sizeof(aa2));
		memset(aa3,0,sizeof(aa3));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++) cin>>a[i][j];
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])
			{
				d1++;
				ans+=a[i][1];
				aa1[i]=1;
			}
			else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])
			{
				d2++;
				ans+=a[i][2];
				aa2[i]=1;
			}
			else if(a[i][3]>a[i][1]&&a[i][3]>a[i][2])
			{
				d3++;
				ans+=a[i][3];
				aa3[i]=1;
			}
			else if(a[i][1]==a[i][2]&&a[i][2]==a[i][3])
			{
				if(d1<d2&&d1<d3)
				{
					d1++;
					ans+=a[i][1];
					aa1[i]=1;
				}
				else if(d2<d1&&d2<d3)
				{
					d2++;
					ans+=a[i][2];
					aa2[i]=1;
				}
				else if(d3<d1&&d3<d2)
				{
					d3++;
					ans+=a[i][3];
					aa3[i]=1;
				}
				else
				{
					num[i]=1;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(num[i]==1)
			{
				if(d1<d2&&d1<d3)
				{
					d1++;
					ans+=a[i][1];
					num[i]--;
					aa1[i]=1;
				}
				else if(d2<d1&&d2<d3)
				{
					d2++;
					ans+=a[i][2];
					num[i]--;
					aa2[i]=1;
				}
				else if(d3<d1&&d3<d2)
				{
					d3++;
					ans+=a[i][3];
					num[i]--;
					aa3[i]=1;
				}
				else
				{
					d1++;
					ans+=a[i][1];
					num[i]--;
					aa1[i]=1;
				}
			}
		}
		fl=1;
		while(fl)
		{
			fl=0;
			if(d1>n/2)
			{
				fl=1;
				memset(za,0,sizeof(za));
				qw=1;
				c=0;
				v=0;
				maxx=-1;
				for(int i=1;i<=n;i++)
				{
					if(aa1[i]=1)
					{
						za[qw][1]=a[i][1];
						za[qw][2]=a[i][2];
						za[qw][3]=a[i][3];
						qw++;
					}
				}
				for(int i=1;i<=qw*2;i+=2)
				{
					t1[i]=za[i][2];
					t1[i+1]=za[i][3];
				}
				for(int i=1;i<=qw*2;i++)
				{
					if(t1[i]>maxx)
					{
						maxx=t1[i];
						c=(i+1)/2;
						if(i%2==1) v=2;
						else v=3;
					}
				}
				if(v=2)
				{
					d1--;
					d2++;
					ans-=a[c][1];
					ans+=a[c][2];
					aa1[c]=0;
					aa2[c]=1;
				}
				else
				{
					d1--;
					d3++;
					ans-=a[c][1];
					ans+=a[c][3];
					aa1[c]=0;
					aa3[c]=1;
				}
			}
			if(fl==0) break;
		}
		fl=1;
		while(fl)
		{
			fl=0;
			if(d2>n/2)
			{
				fl=1;
				memset(za,0,sizeof(za));
				qw=1;
				c=0;
				v=0;
				maxx=-1;
				for(int i=1;i<=n;i++)
				{
					if(aa2[i]=1)
					{
						
						za[qw][1]=a[i][1];
						za[qw][2]=a[i][2];
						za[qw][3]=a[i][3];
						qw++;
					}
				}
				for(int i=1;i<=qw*2;i+=2)
				{
					
					t1[i]=za[i][1];
					t1[i+1]=za[i][3];
				}
				for(int i=1;i<=qw*2;i++)
				{
					if(t1[i]>maxx)
					{
						
						maxx=t1[i];
						c=(i+1)/2;
						if(i%2==1) v=2;
						else v=3;
					}
				}
				if(v=2)
				{
					d2--;
					d1++;
					ans-=a[c][2];
					ans+=a[c][1];
					aa2[c]=0;
					aa1[c]=1;
				}
				else
				{
					d2--;
					d3++;
					ans-=a[c][2];
					ans+=a[c][3];
					aa2[c]=0;
					aa3[c]=1;
				}
			}
			if(fl==0) break;
		}
		fl=1;
		while(true)
		{
			fl=0;
			if(d3>n/2)
			{
				fl=1;
				memset(za,0,sizeof(za));
				qw=1;
				c=0;
				v=0;
				maxx=-1;
				for(int i=1;i<=n;i++)
				{
					if(aa3[i]=1)
					{
						za[qw][1]=a[i][1];
						za[qw][2]=a[i][2];
						za[qw][3]=a[i][3];
						qw++;
					}
				}
				for(int i=1;i<=qw*2;i+=2)
				{
					t1[i]=za[i][1];
					t1[i+1]=za[i][2];
				}
				for(int i=1;i<=qw*2;i++)
				{
					if(t1[i]>maxx)
					{
						maxx=t1[i];
						c=(i+1)/2;
						if(i%2==1) v=2;
						else v=3;
					}
				}
				if(v=2)
				{
					d3--;
					d1++;
					ans-=a[c][3];
					ans+=a[c][1];
					aa3[c]=0;
					aa1[c]=1;
				}
				else
				{
					d3--;
					d2++;
					ans-=a[c][3];
					ans+=a[c][2];
					aa3[c]=0;
					aa2[c]=1;
				}
			}
			if(fl==0) break;
		}
	cout<<ans<<endl;
	}

	return 0;
}
