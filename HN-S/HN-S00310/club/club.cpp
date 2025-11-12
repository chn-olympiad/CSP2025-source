#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	int a[10001][10];
	int q=0,w=0,e=0;
	int sum=0;
	int minn=898989897;
	int pa=0;
	int v,v2,b,b2,r,r2;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=3;k++)
			{
				cin>>a[j][k];
			}
			
			sum+=max(a[j][1],max(a[j][2],a[j][3]));
			
			if(max(a[j][1],max(a[j][2],a[j][3]))==a[j][1])
			{
				q++;
			}
			else if(max(a[j][1],max(a[j][2],a[j][3]))==a[j][2])
			{
				w++;
			}
			else
			{
				e++;
			}
				
			
			if(q>n/2)
			{
				for(int c=1;c<=n;c++)
				{
					v=max(a[c][1],a[c][2])-min(a[c][1],a[c][2]);
					b=max(a[c][1],a[c][3])-min(a[c][1],a[c][3]);
					r=max(a[c][2],a[c][3])-min(a[c][2],a[c][3]);
					if(v==0)
					{
						minn=min(min(b,r),minn);
					}
					else if(b==0)
					{
						minn=min(min(v,r),minn);
					}
					else if(r==0)
					{
						minn=min(min(v,b),minn);
					}
					else
					minn=min(min(v,min(b,r)),minn);
				}
				for(int c=1;c<=n;c++)
				{
					if(minn==min(max(a[c][1],a[c][2])-min(a[c][1],a[c][2]),min(max(a[c][1],a[c][3])-min(a[c][1],a[c][3]),max(a[c][2],a[c][3])-min(a[c][2],a[c][3]))))
					{
						pa=c;
					}
				}
				if(a[pa][2]>a[pa][3])
				{
					sum-=a[pa][1];
					sum+=a[pa][2];
					q--;
					w++;
				}
				else if(a[pa][2]==a[pa][3])
				{
					sum-=a[pa][1];
					sum+=a[pa][2];
					a[pa][2]-=a[pa][2]+1;
					q--;
					w++;
				}
				else
				{
					sum-=a[pa][1];
					sum+=a[pa][3];
					q--;
					e++;
				}
			}
			if(w>n/2)
			{
				for(int c=1;c<=n;c++)
				{
					v=max(a[c][1],a[c][2])-min(a[c][1],a[c][2]);
					b=max(a[c][1],a[c][3])-min(a[c][1],a[c][3]);
					r=max(a[c][2],a[c][3])-min(a[c][2],a[c][3]);
					
					if(v==0)
					{
						minn=min(min(b,r),minn);
					}
					else if(b==0)
					{
						minn=min(min(v,r),minn);
					}
					else if(r==0)
					{
						minn=min(min(v,b),minn);
					}
					else
					minn=min(min(v,min(b,r)),minn);
				}
				for(int c=1;c<=n;c++)
				{
					if(minn==min(max(a[c][1],a[c][2])-min(a[c][1],a[c][2]),min(max(a[c][1],a[c][3])-min(a[c][1],a[c][3]),max(a[c][2],a[c][3])-min(a[c][2],a[c][3]))))
					{
						pa=c;
					}
				}
				if(a[pa][1]>a[pa][3])
				{
					sum-=a[pa][2];
					sum+=a[pa][1];
					w--;
					q++;
				}
				else if(a[pa][1]==a[pa][3])
				{
					sum-=a[pa][2];
					sum+=a[pa][1];
					a[pa][1]-=a[pa][1]+1;
					w--;
					q++;
				}
				else
				{
					sum-=a[pa][2];
					sum+=a[pa][3];
					w--;
					e++;
				}
			}
			if(e>n/2)
			{
				for(int c=1;c<=n;c++)
				{
					v=max(a[c][1],a[c][2])-min(a[c][1],a[c][2]);
					b=max(a[c][1],a[c][3])-min(a[c][1],a[c][3]);
					r=max(a[c][2],a[c][3])-min(a[c][2],a[c][3]);
					
					if(v==0)
					{
						minn=min(min(b,r),minn);
					}
					else if(b==0)
					{
						minn=min(min(v,r),minn);
					}
					else if(r==0)
					{
						minn=min(min(v,b),minn);
					}
					else
					minn=min(min(v,min(b,r)),minn);
				}
				for(int c=1;c<=n;c++)
				{
					if(minn==min(max(a[c][1],a[c][2])-min(a[c][1],a[c][2]),min(max(a[c][1],a[c][3])-min(a[c][1],a[c][3]),max(a[c][2],a[c][3])-min(a[c][2],a[c][3]))))
					{
						pa=c;
					}
				}
				if(a[pa][1]>a[pa][2])
				{
					sum-=a[pa][3];
					sum+=a[pa][1];
					e--;
					q++;
				}
				else if(a[pa][1]==a[pa][2])
				{
					sum-=a[pa][3];
					sum+=a[pa][1];
					a[pa][1]-=a[pa][1]+1;
					e--;
					q++;
				}
				else
				{
					sum-=a[pa][3];
					sum+=a[pa][2];
					e--;
					w++;
				}
			}
			
		}
		cout<<sum<<endl;
		v=0;
			b=0;
			r=0;
			minn=898989897;
			pa=0;
			q=0;
			w=0;
			e=0;
		sum=0;
	}
	return 0;
}






