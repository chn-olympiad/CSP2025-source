#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,sum,a[N][4],cnt[4],num[4][N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			sum+=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
				num[1][++cnt[1]]=a[i][1]-max(a[i][2],a[i][3]);
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
				num[2][++cnt[2]]=a[i][2]-max(a[i][1],a[i][3]);
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])
				num[3][++cnt[3]]=a[i][3]-max(a[i][1],a[i][2]);
		}
		for(int i=1;i<=3;i++)
		{
			if(cnt[i]>(n/2))
			{
				sort(num[i]+1,num[i]+1+cnt[i]);
				for(int j=1;j<=cnt[i]-(n/2);j++)
					sum-=num[i][j];
				break;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
