#include<bits/stdc++.h>
using namespace std;
int t,n,a[5005][3],m0[10005],m1[10005],m2[10005],c0,c1,c2,mx=-2147483648,ans;
long long mh0,mh1,mh2;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ans=0;
		
		mh0=0;
		mh1=0;
		mh2=0;
		c0=0,c1=0,c2=0;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>a[j][0]>>a[j][1]>>a[j][2];
			m0[j]=a[j][0]-a[j][1]-a[j][2];
			m1[j]=a[j][1]-a[j][0]-a[j][2];
			m2[j]=a[j][2]-a[j][0]-a[j][1];
			mh0+=a[j][0];
			mh1+=a[j][1];
			mh2+=a[j][2];
		}
		for(int j=0;j<n;j++)
		{
			mx=-2147483648;
			if((c0!=n/2)&&(mh0>=mh1||c1==n/2)&&(mh0>=mh2||c2==n/2))
			{
				for(int k=0;k<n;k++)
				{
					mx=max(mx,m0[k]);
				}
				for(int k=0;k<n;k++)
				{
					if(mx==m0[k])
					{
						ans+=a[k][0];
						m0[k]=-2147483648;
						m1[k]=-2147483648;
						m2[k]=-2147483648;
						mh0-=a[k][0];
						mh1-=a[k][1];
						mh2-=a[k][2];
						c0++;
						//cout<<"第"<<k+1<<"名学生加入了club1,满意度为"<<a[k][0]<<",club1中现有"<<c0<<"人,club1的满意度总和为"<<mh0<<"\n";
						break;
					}
				}
			}
			else if((c1!=n/2)&&(mh1>=mh0||c0==n/2)&&(mh1>=mh2||c2==n/2))
			{
				for(int k=0;k<n;k++)
				{
					mx=max(mx,m1[k]);
				}
				for(int k=0;k<n;k++)
				{
					if(mx==m1[k])
					{
						ans+=a[k][1];
						m0[k]=-2147483648;
						m1[k]=-2147483648;
						m2[k]=-2147483648;
						mh1-=a[k][1];
						mh0-=a[k][0];
						mh2-=a[k][2];
						c1++;
						//cout<<"第"<<k+1<<"名学生加入了club2,满意值为"<<a[k][1]<<",club2中现有"<<c1<<"人,club2的满意度总和为"<<mh1<<"\n";
						break;
					}
				}
			}
			else
			//if((c2!=n/2)&&(mh2>=mh1||c1==n/2)&&(mh2>=mh0||c0==n/2))
			{
				for(int k=0;k<n;k++)
				{
					mx=max(mx,m2[k]);
				}
				for(int k=0;k<n;k++)
				{
					if(mx==m2[k])
					{
						ans+=a[k][2];
						m0[k]=-2147483648;
						m1[k]=-2147483648;
						m2[k]=-2147483648;
						mh2-=a[k][2];
						mh1-=a[k][1];
						mh0-=a[k][0];
						c2++;
						//cout<<"第"<<k+1<<"名学生加入了club3,满意值为"<<a[k][2]<<",club3中现有"<<c2<<"人,club3的满意度总和为"<<mh2<<"\n";
						break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
