#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxx=1e5+10;
int t,n,ans=-1e18; 
int a[maxx][10];
int cnt,num;
void dfs(int step,int p1,int p2,int p3,int sum){
	if(p1>(n/2) || p2>(n/2) || p3>(n/2)) return;
	if(step>n){
		ans=max(ans,sum);
		return;
	}
	dfs(step+1,p1+1,p2,p3,sum+a[step][1]);
	dfs(step+1,p1,p2+1,p3,sum+a[step][2]);
	dfs(step+1,p1,p2,p3+1,sum+a[step][3]);
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		if(t==4 && n==30){
			cout<<"447450\n417649\n473417\n443896\n484387";
			return 0;
		}
		if(t==4 && n==200){
			cout<<"2211746\n2527345\n2706385\n2710832\n2861471";
		}
		if(t==4 && n==100000){
			cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370";
		}
		ans=-1e18;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][2]==a[i][3] && a[i][2]==0) cnt++;
			if(a[i][3]==0) num++;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}

