#include<iostream>
using namespace std;
int n,m,k;
int mp[10000][10000];
bool fg[10000];
//int hd[10000],nxt[1000000],e[1000000],v[1000000],tot;
//void add(int st,int ed,int val){
//	tot++;
//	e[tot]=ed;
//	v[tot]=val;
//	nxt[tot]=hd[st];
//	hd[st]=tot;
//}
int dp[10000][10000];
int pm(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i!=j&&j!=k&&i!=k){
					dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
					dp[j][i]=dp[i][j];
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	int ans=0;
	fg[1]=1;
	for(int x=1;x<n;x++){
		for(int i=2;i<=n;i++){
			if(!fg[i]){
//				cout<<i<<endl;
				ans+=dp[1][i];
//				cout<<ans<<endl;
				fg[i]=1;
				for(int j=2;j<=n;j++){
					if(dp[1][j]+dp[j][i]==dp[1][i]&&(!fg[j])&&j!=i){
//						cout<<j<<endl;
						fg[j]=1;
					}
					else if(dp[1][j]+dp[j][i]==dp[1][i]&&fg[j]&&j!=i){
//						cout<<"*"<<j;
						ans-=dp[1][j];
					}
				}	
			}
			
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fg[i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)dp[i][j]=1e9;
	for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int i=1;i<=m;i++){
		int st,ed,val;
		cin>>st>>ed>>val;
		if(mp[st][ed]!=0){
			mp[st][ed]=max(mp[st][ed],val);
			mp[ed][st]=max(mp[ed][st],val);
			dp[st][ed]=max(mp[st][ed],val);
			dp[ed][st]=max(mp[ed][st],val);
		}
		else{
			mp[st][ed]=val;
			mp[ed][st]=val;
			dp[st][ed]=val;
			dp[ed][st]=val;
		}
	}
//	cout<<pm();
	int ans=1e9;
	int ans1=pm();
//	cout<<ans1;
	ans=min(ans,ans1);
	int c=0;
	for(int x=1;x<=k;x++){
		for(int i=1;i<=n;i++)fg[i]=0;
		int c1,a[1000000];
		cin>>c1;
		c+=c1;
		if(c==0){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dp[i][j]=min(a[i]+a[j],dp[i][j]);
				dp[j][i]=dp[i][j];
			}
		}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//		cout<<ans<<endl;
		ans=min(ans,pm()+c);
	}
	cout<<ans;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
*/
