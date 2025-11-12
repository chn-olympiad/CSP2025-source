#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,s=0;
		cin>>n;
		int a[100010],b[100010],c[100010];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1);
		for(int i=n/2+1;i<=n;i++)
		s+=a[i];
		cout<<s<<endl;
		
		/*			int s=0;
		int n;
		int a[100010],b[100010],c[100010],s1[100010],s2[100010],s3[100010],a1=0,b1=0,c1=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{

			cin>>a[i]>>b[i]>>c[i];
			int max1=max(max(a[i],b[i]),c[i]);
			s+=max1;
			if(max1==a[i])
			{
				s1[i]=-1e7;
				a1++;
				}
			else if(max1==b[i]){
				b1++;
				s2[i]=-1e7;
			}
			else
			{ c1++;
				s3[i]=-1e7;}
			if(a1>n/2)
			{
				int maxb=-1e7,maxc=-1e7,p=0,q=0;
				for(int j=1;j<i;j++)
				{
					if(s2[j]>maxb)
					{
						maxb=s2[j];
						p=j;
					}
					if(s3[j]>maxc)
					{
						maxc=s3[j];
						q=j;
					}
					
				}
				if(-max(maxb,maxc)<max1)
				{
				if(maxb>=maxc&&b1+1<=n/2)
				{
					s+=maxb;
					a1--;
					b1++;
					s1[p]+=1e7;
					s2[p]-=1e7;
					s3[p]-=maxb;
				}				
				else
				{
					s+=maxc;
					a1--;
					c1++;
					s1[q]+=1e7;
					s2[q]-=maxc;
					s3[q]-=1e7;
				}	
				}	
				else
				{
					s1[i]+=1e7;
					if(b[i]>c[i])
					{
						s-=max1;

						s+=b[i];
						b1++;
						max1=b[i];
						s2[i]-=1e7;
					}
					else
					{
						s-=max1;
						s+=c[i];
						c1++;
						max1=c[i];
						s3[i]-=1e7;
					}
				}
			}
			else if(b1>n/2)
			{
				int maxa=-1e7,maxc=-1e7,p=0,q=0;
				for(int j=1;j<i;j++)
				{
					if(s1[j]>maxa)
					{
						maxa=s1[j];
						p=j;
					}
					if(s3[j]>maxc)
					{
						maxc=s3[j];
						q=j;
					}
					
				}
				if(-max(maxa,maxc)>=max1)
				{
					s2[i]+=1e7;
					
					if(a[i]>c[i])
					{
						s-=max1;
						s+=a[i];
						a1++;
						s1[i]-=1e7;
						max1=a[i];
					}
					else
					{
						s-=max1;
						s+=c[i];
						c1++;
						s3[i]-=1e7;
						max1=c[i];
					}
				
				}
				else
				{
				if(maxa>=maxc&&a1+1<=n/2)
				{
					s+=maxa;
					b1--;
					a1++;
					s1[p]-=1e7+maxa;
					s2[p]+=1e7-maxa;
					s3[p]-=maxa;
				}				
				else
				{
					s+=maxc;
					b1--;
					c1++;
					s1[q]-=maxc;
					s2[q]-=maxc;
					s3[q]-=maxc;
				}	
				}	
			}
			else if(c1>n/2)
			{
				int maxa=-1e7,maxb=-1e7,p=0,q=0;
				for(int j=1;j<i;j++)
				{
					if(s1[j]>maxa)
					{
						maxa=s1[j];
						p=j;
					}
					if(s2[j]>maxb)
					{
						maxb=s2[j];
						q=j;
					}
					
				}
				if(-max(maxa,maxb)>=max1)
				{
					if(a[i]>b[i])
					{
						s-=max1;
						s+=a[i];
						a1++;
						max1=a[i];
					}
					else
					{
						s-=max1;
						s+=b[i];
						b1++;
						max1=b[i];
					}
				}
				else
				{
				if(maxa>=maxb&&a1+1<=n/2)
				{
					s+=maxa;
					c1--;
					a1++;
					s1[p]-=maxa;
					s2[p]-=maxa;
					s3[p]-=maxa;
				}				
				else
				{
					s+=maxb;
					c1--;
					b1++;
					s1[q]-=maxb;
					s2[q]-=maxb;
					s3[q]-=maxb;
				}	
				}	
			}
			s1[i]=a[i]-max1;
			s2[i]=b[i]-max1;
			s3[i]=c[i]-max1;
			cout<<s<<' ';
		}
		cout<<s<<endl;*/

}
}
