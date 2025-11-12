#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=1e5+5,INF=1e9;
int a[N][4];
int vis[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int T;cin>>T;
	while(T--)
	{
		int n;cin>>n;
		for(int i=1;i<=n;i++) vis[i]=0;
		int c1=0,c2=0,c3=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) c1++,vis[i]=1,ans+=a[i][1];
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) c2++,vis[i]=2,ans+=a[i][2];
			else c3++,vis[i]=3,ans+=a[i][3];
		}
		int flag=-1,cnt=0;
		if(c1>n/2) flag=1,cnt=c1-n/2;
		else if(c2>n/2) flag=2,cnt=c2-n/2;
		else if(c3>n/2) flag=3,cnt=c3-n/2;
		if(flag!=-1){
			priority_queue<int,vector<int>,greater<int>> Q;
			for(int i=1;i<=n;i++){
				if(vis[i]==flag){
					int minn=INF;
					for(int j=1;j<=3;j++){
						if(j==flag) continue;
						minn=min(minn,a[i][flag]-a[i][j]);
					}
					Q.push(minn);
				}
			}
			for(int i=1;i<=cnt;i++){
				ans-=Q.top();
				Q.pop();
			}
		}
		cout<<ans<<'\n';
	}
	return 0; 
}
