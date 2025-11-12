#include <bits/stdc++.h>
using namespace std;
int T;
int n,ans,a[100005][3],f[100005];
int cnt[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(cnt,0,sizeof(cnt));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int j=1;
			if(f[i-1]+a[i][j]>f[i]&&cnt[j]+1<=n/2)
			{
				f[i]=max(f[i-1]+max(a[i][1],max(a[i][2],a[i][3])),f[i]);
				cnt[j]++;
			}
			else if(cnt[j]>n/2)
			{
				f[i]=max(f[i],f[i-1]);
			}
		}
		cout<<f[n]<<'\n';
	}
	return 0;
 } 
