#include<bits/stdc++.h>
using namespace std;
int a[5][100005],s[5],ans,n;
int c[5][100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		ans=s[1]=s[2]=s[3]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[1][i]>a[2][i]&&a[1][i]>a[3][i])
			{
				s[1]++;
				c[1][s[1]]=a[1][i]-max(a[2][i],a[3][i]);
				ans+=a[1][i];
			 } 
			else if(a[2][i]>a[3][i])
			{
				s[2]++;
				c[2][s[2]]=a[2][i]-max(a[1][i],a[3][i]);
				ans+=a[2][i];
			} 
			else
			{
				s[3]++;
				c[3][s[3]]=a[3][i]-max(a[2][i],a[1][i]);
				ans+=a[3][i];
			}
		}
	//	cout<<s[1]<<" "<<s[2]<<" "<<s[3]<<endl;
		if(s[1]<=n/2&&s[2]<=n/2&&s[3]<=n/2)
		{
			cout<<ans<<endl;
		}
		else
		{
			if(s[1]>n/2)
			{
				sort(c[1]+1,c[1]+s[1]+1);
				int o=1;
				for(int i=s[1];i>n/2;i--)
				{
					ans-=c[1][o];
					o++;
				}
			}
			else if(s[2]>n/2)
			{
				sort(c[2]+1,c[2]+s[2]+1);
				int o=1;
				for(int i=s[2];i>n/2;i--)
				{
					ans-=c[2][o];
					o++;
				}
			}
			else
			{
				sort(c[3]+1,c[3]+s[3]+1);
				int o=1;
				for(int i=s[3];i>n/2;i--)
				{
					ans-=c[3][o];
					o++;
				}
			}
			cout<<ans<<endl;
		}
	 } 
	return 0;
 } 
