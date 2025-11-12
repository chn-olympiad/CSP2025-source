/*
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t;
int w[N][4],dp[N],cnt1[N],cnt2[N],cnt3[N];
signed main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&w[i][1],&w[i][2],&w[i][3]);
		for(int i=1;i<=n;i++)
			for(int k=1;k<=3;k++)
				dp[i]=max(dp[i-1]+w[i][k],dp[i]);
		cout<<dp[n]<<endl;
	}
	return 0;
}

//*/

//*
#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=1e5+5;
int n,t;
int w[N][4],a[N],cnt1,cnt2,cnt3,ans; 
void dfs(int x,int cnt){
//	cout<<x<<" "<<cnt<<endl;
	if(x==n+1){
		ans=max(ans,cnt);
		return ;
	}
	if(cnt1<n/2){
		cnt1++;
		dfs(x+1,cnt+w[x][1]);
		cnt1--;
	}
	if(cnt2<n/2){
		cnt2++;
		dfs(x+1,cnt+w[x][2]);
		cnt2--;
	}
	if(cnt3<n/2){
		cnt3++;
		dfs(x+1,cnt+w[x][3]);
		cnt3--;
	}		
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int flg=1;
		ans=0;
		cin>>n;
		if(n>10000) flg=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&w[i][1],&w[i][2],&w[i][3]);
			if(w[i][2]!=0 || w[i][3]!=0)
				flg=0;
		}if(flg==0){
			dfs(1,0);
			cout<<ans<<endl;
		}else{
			for(int i=1;i<=n;i++) a[i]=w[i][1];
			sort(a+1,a+n+1);
			for(int i=n/2+1;i<=n;i++) ans+=a[i];
			cout<<ans<<endl;
		}
	}
	return 0;
}

//*/



/*
3 
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
