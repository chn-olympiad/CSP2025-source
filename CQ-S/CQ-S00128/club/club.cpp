#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+10,M=1e5+10;
int n,a[M][5],c[M],ans;
void dfs(int dep,int cnt1,int cnt2,int cnt3,int sum){
	if(dep==n+1){
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			ans=max(ans,sum);
			//cout<<"sum="<<sum<<'\n';
		}
		return;
	}
	dfs(dep+1,cnt1+1,cnt2,cnt3,sum+a[dep][1]);
	dfs(dep+1,cnt1,cnt2+1,cnt3,sum+a[dep][2]);
	dfs(dep+1,cnt1,cnt2,cnt3+1,sum+a[dep][3]);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		bool f=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==2||j==3){
					if(a[i][j]!=0) f=0;
				}
			}
		}
		if(f){
			for(int i=1;i<=n;i++){
				c[i]=a[i][1];
			}	
			sort(c+1,c+n+1);
			for(int i=n;i>n/2;i--){
				ans+=c[i];
			}
			cout<<ans<<'\n';
			ans=0;
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}


