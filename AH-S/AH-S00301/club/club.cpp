#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,a[100005][5],dp[50005][5],b[100005],mx;
bool cmp(const ll &x,const ll &y){
	return x>y;
}
void dfs(ll cur,ll c1,ll c2,ll c3,ll sum){
	if(cur==n+1){
		mx=max(mx,sum);
		return ;
	}
	if(c1+1<=n/2){
		dfs(cur+1,c1+1,c2,c3,sum+a[cur][1]);
	}
	if(c2+1<=n/2){
		dfs(cur+1,c1,c2+1,c3,sum+a[cur][2]);
	}
	if(c3+1<=n/2){
		dfs(cur+1,c1,c2,c3+1,sum+a[cur][3]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		bool flag=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i]=a[i][1];
			if(a[i][2]!=0||a[i][3]!=0){
				flag=1;
			}
		}
		if(n==2){
			ll p[3],minn[3];
			for(int i=1;i<=2;i++){
				ll maxn=max(a[i][1],max(a[i][2],a[i][3]));
				minn[i]=min(a[i][1],min(a[i][2],a[i][3]));
				if(maxn==a[i][1]){
					p[i]=1;
				}
				else if(maxn==a[i][2]){
					p[i]=2;
				}
				else{
					p[i]=3;
				}
			}
			if(p[1]!=p[2]){
				cout<<a[1][p[1]]+a[2][p[2]]<<endl;
				continue;
			}
			minn[1]=a[1][1]+a[1][2]+a[1][3]-a[1][p[1]]-minn[1];
			minn[2]=a[2][1]+a[2][2]+a[2][3]-a[2][p[2]]-minn[2];
			cout<<max(minn[1]+a[2][p[2]],minn[2]+a[1][p[1]])<<endl;
			continue;
		}
		if(flag==0){
			sort(b+1,b+n+1,cmp);
			ll ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=b[i];
			}
			cout<<ans<<endl;
			continue;
		}
		mx=0;
		dfs(1,0,0,0,0);
		cout<<mx<<endl;
	}
	return 0;
}
