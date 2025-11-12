//GZ-S00015 贵阳市南明区华麟学校 代钰涵 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10; 
int t,n,p[N],a[N][4],q[N][4],s[N],ldl,cnt[4],cnt1=1,cnt2=1,b[N],e[N],ccf[N];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ldl=-114514;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			s[i]=0,cnt1=1,cnt2=1,e[i]=0;
			for(int j=1;j<=3;j++)
			{
				q[i][j]=0;
				cnt[j]=0;
				cin>>a[i][j];
				if(a[i][3]!=0) cnt1=0;
				if(a[i][2]!=0) cnt2=0;
			}
		}
		if(n==2)
		{
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(i!=j)
					{
						if(ldl<a[1][i]+a[2][j])
						{
							ldl=a[1][i]+a[2][j];
						}
					}
					
				}
			}
			cout<<ldl<<endl;
		}
		else if(cnt1==1&&cnt2==1)
		{
			for(int i=1;i<=n;i++)
			{
				b[i]=a[i][1];
			}
			sort(b+1,b+1+n);
			for(int i=n;i>=n/2;i--) ldl+=b[i];
			cout<<ldl<<endl;
		} 
		else
		{
			ldl=0;
			for(int i=1;i<=n;i++)
			{
				s[i]=-1;
				for(int j=1;j<=3;j++)
				{
					if(q[i][j]==0&&s[i]<a[i][j])
					{
						s[i]=a[i][j];
						p[i]=j;
					}
				}
				ccf[i]=a[i][p[i]];
				for(int j=1;j<=3;j++)
				{ 
					if(p[i]!=j&&q[i][j]==0)
					{
						e[i]=min(a[i][p[i]]-a[i][j],e[i]);
					}
				}
				if(cnt[p[i]]+1>(n/2))
				{
					int rm=INT_MAX,bc=0;
					for(int j=1;j<=i;j++)
					{
						if(e[j]<rm&&e[j]!=0) rm=e[j],bc=j;
					}
					q[bc][p[i]]=1;
					i=bc;
				}
				cnt[p[i]]++;
			}
			for(int i=1;i<=n;i++) ldl+=ccf[i];
			cout<<ldl<<endl;
		}	
	} 
	return 0;
}
