#include<bits/stdc++.h>
using namespace std;
int f[5010][5010];
int t,n,a[100010][5],cntA,cntB;
long long ans;
void dfs(int i,int cnt1,int cnt2,int cnt3,long long sum){
	if(cnt1>n/2||cnt2>n/2||cnt3>n/2) return ;
	if(i>n){
		ans=max(ans,sum);
		return ;
	}
	dfs(i+1,cnt1+1,cnt2,cnt3,sum+a[i][1]);
	dfs(i+1,cnt1,cnt2+1,cnt3,sum+a[i][2]);
	dfs(i+1,cnt1,cnt2,cnt3+1,sum+a[i][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]==0&&a[i][3]==0) cntA++;
			if(a[i][3]==0) cntB++;
		}
		if(cntA==n){
			int b[100010];
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+1+n);
			for(int i=n;i>=n/2;i--){
				ans+=b[i];
			}
			cout<<ans<<endl;
		}else if(cntB==n){
			for(int i=1;i<=n/2;i++){
				for(int j=1;j<=n/2;j++){
					f[i][j]=max(f[i-1][j]+a[i][1],f[i][j-1]+a[i][2]);
				}
			}
			cout<<f[n/2][n/2]<<endl;	
		}else if(n<=30){
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}else{
			for(int i=1;i<=n;i++){
				ans+=max(a[i][1],max(a[i][2],a[i][3]));
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
