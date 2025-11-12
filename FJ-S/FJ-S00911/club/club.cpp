#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,nn,ans;

struct node{
	int fir,sec,thi;
}a[200005];

struct node2{
	int sum,firs,seco,thir;
}dp[200005][4];

bool cmp1(node xx,node yy){
	return xx.fir>yy.fir;
}
bool cmp2(node xx,node yy){
	return xx.sec>yy.sec;
}
bool cmp3(node xx,node yy){
	return xx.thi>yy.thi;
}
bool bj=1,bjj=1,bjjj=1;
void dfs1(int firs,int seco,int thir,int sum,int ii){
	if(firs>nn||seco>nn){
		return ;
	}
	if(ii==n){
		ans=max(ans,sum);
		return;
	}
	dfs1(firs+1,seco,thir,sum+a[ii].fir,ii+1);
	dfs1(firs,seco+1,thir,sum+a[ii].sec,ii+1);
	return ;
}
void dfs2(int firs,int seco,int thir,int sum,int ii){
	if(firs>nn||seco>nn||thir>nn){
		return ;
	}
	if(ii==n+1){
	//	cout<<firs<<" "<<seco<<" "<<thir<<" "<<ans<<" "<<sum<<'\n';
		ans=max(ans,sum);
		return;
	}
	dfs2(firs+1,seco,thir,sum+a[ii].fir,ii+1);
	dfs2(firs,seco+1,thir,sum+a[ii].sec,ii+1);
	dfs2(firs,seco,thir+1,sum+a[ii].thi,ii+1);
	return ;
}
void solve(){
	cin>>n;
	nn=n/2;
	bjj=1;
	bj=1;
	bjjj=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].fir>>a[i].sec>>a[i].thi;
		if(a[i].fir!=0){
			bj=0;
		}
		if(a[i].sec!=0){
			bjj=0;
		}
		if(a[i].thi!=0){
			bjjj=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			dp[i][j].sum=dp[i][j].firs=dp[i][j].seco=dp[i][j].thir=0;
		}
	}
	if(bjj==1&&bjjj==1){
		sort(a+1,a+1+n,cmp1);
		ans=0;
		for(int i=1;i<=nn;i++){
			ans+=a[i].fir;
		}
		cout<<ans<<'\n';
		return ;
	}else if(bj==1&&bjjj==1){
		sort(a+1,a+1+n,cmp2);
		ans=0;
		for(int i=1;i<=nn;i++){
			ans+=a[i].sec;
		}
		cout<<ans<<'\n';
		return ;
	}else if(bj==1&&bjj==1){
		sort(a+1,a+1+n,cmp3);
		ans=0;
		for(int i=1;i<=nn;i++){
			ans+=a[i].thi;
		}
		cout<<ans<<'\n';
		return ;
	}else /*if(bjj==1){
		ans=0;
		dfs1(0,0,0,0,1);
		cout<<ans<<'\n';
		return;
	}else{
		cout<<"1 ";*/
		if(n<=10){
			ans=0;
			dfs2(0,0,0,0,1);
			cout<<ans<<'\n';
			return;
		}else{
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(dp[i-1][j].firs<nn){
					if(dp[i-1][j].sum+a[i].fir>dp[i][1].sum){
						dp[i][1].sum=dp[i-1][j].sum+a[i].fir;
						dp[i][1].firs=dp[i-1][j].firs+1;
						dp[i][1].seco=dp[i-1][j].seco;
						dp[i][1].thir=dp[i-1][j].thir;
					}
				}	
				if(dp[i-1][j].seco<nn){
					if(dp[i-1][j].sum+a[i].sec>dp[i][2].sum){
						dp[i][2].sum=dp[i-1][j].sum+a[i].sec;
						dp[i][2].firs=dp[i-1][j].firs;
						dp[i][2].seco=dp[i-1][j].seco+1;
						dp[i][2].thir=dp[i-1][j].thir;
					}
				}	
				if(dp[i-1][j].thir<nn){
					if(dp[i-1][j].sum+a[i].thi>dp[i][3].sum){
						dp[i][3].sum=dp[i-1][j].sum+a[i].thi;
						dp[i][3].firs=dp[i-1][j].firs;
						dp[i][3].seco=dp[i-1][j].seco;
						dp[i][3].thir=dp[i-1][j].thir+1;
					}
				}	
			}
		}
/*			cout<<i<<":\n";
			cout<<dp[i][1].sum<<" "<<dp[i][1].firs<<" "<<dp[i][1].seco<<" "<<dp[i][1].thir<<" \n";
			cout<<dp[i][2].sum<<" "<<dp[i][2].firs<<" "<<dp[i][2].seco<<" "<<dp[i][2].thir<<" \n";
			cout<<dp[i][3].sum<<" "<<dp[i][3].firs<<" "<<dp[i][3].seco<<" "<<dp[i][3].thir<<" \n";
		}
		if(max(dp[n][1].sum,max(dp[n][2].sum,dp[n][3].sum))==dp[n][1].sum){
			cout<<1<<" ";
		}
		if(max(dp[n][1].sum,max(dp[n][2].sum,dp[n][3].sum))==dp[n][2].sum){
			cout<<2<<" ";
		}
		if(max(dp[n][1].sum,max(dp[n][2].sum,dp[n][3].sum))==dp[n][3].sum){
			cout<<3<<" ";
		}
		cout<<dp[n][1].sum<<" "<<dp[n][2].sum<<" "<<dp[n][3].sum<<" "; */
		cout<<max(dp[n][1].sum,max(dp[n][2].sum,dp[n][3].sum))<<'\n';
	}
	return ;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
