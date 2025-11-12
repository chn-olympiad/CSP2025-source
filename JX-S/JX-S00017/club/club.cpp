#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100001;
int t,n,a[N][4],num[4],ans,sum,v,b[N];
void dfs(int x){
	for(int i=1;i<=3;i++){
		if(num[i]<n/2){
			sum+=a[x][i];
			num[i]++;
			if(x+1<=n)dfs(x+1);
			ans=max(ans,sum);
			sum-=a[x][i];
			num[i]--;
		}
	}
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		ans=0,sum=0,v=0;
		memset(num,0,sizeof(num));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0)v=1;
		}
		if(v==0){
			for(int i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+n+1);
			for(int i=n/2+1;i<=n;i++)ans+=b[i];
			cout<<ans<<endl;
			continue;
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
