#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t,n,ans;
struct people{
	int a1,a2,a3;
}a[maxn];
bool vis[maxn];
int c[maxn],f[maxn][2][2][2];
int cnt1,cnt2;
void dfs(int c1,int c2,int c3,int sum,int t)
{
	if(c1+c2+c3==n){
		ans=max(ans,sum);
		return;
	}
	if(c1<n/2) dfs(c1+1,c2,c3,sum+a[t+1].a1,t+1);
	if(c2<n/2) dfs(c1,c2+1,c3,sum+a[t+1].a2,t+1);
	if(c3<n/2) dfs(c1,c2,c3+1,sum+a[t+1].a3,t+1);
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		if(n<=30){
			for(int i=1;i<=n;i++)
				cin>>a[i].a1>>a[i].a2>>a[i].a3;
			dfs(0,0,0,0,0);
			cout<<ans<<"\n";
		}
		else{
			for(int i=1;i<=n;i++){
				cin>>a[i].a1>>a[i].a2>>a[i].a3;
				cnt1+=(a[i].a2==0);
				cnt2+=(a[i].a3==0);
			}
			if(cnt1==0 && cnt2==0){
				for(int i=1;i<=n;i++)
					c[i]=a[i].a1;
				sort(c+1,c+1+n,cmp);
				for(int i=1;i<=n/2;i++)
					ans+=c[i];
				cout<<ans<<"\n";
			}
			else if(cnt2==0){
				memset(f,0,sizeof(f));
				for(int i=1;i<=n;i++)
					cin>>a[i].a1>>a[i].a2>>a[i].a3;
				for(int i=1;i<=n;i++){
					f[i][1][0][0]=max(f[i-1][0][1][0],f[i-1][0][0][1])+a[i].a1;
					f[i][0][1][0]=max(f[i-1][1][0][0],f[i-1][0][0][1])+a[i].a2;
					f[i][0][0][1]=max(f[i-1][0][1][0],f[i-1][1][0][0])+a[i].a3;
				}
				cout<<max(f[n][1][0][0],max(f[n][0][1][0],f[n][0][0][1]))<<"\n";
			}
		}
	}
	return 0;
}

