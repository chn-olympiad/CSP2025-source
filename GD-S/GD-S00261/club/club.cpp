#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,NN=35;
long long n,m,ans,ap[NN][4],pps[N];//,mmap[N][3];
struct DP{
	bool operator <(const DP &oth)const{
		if(a[0]!=oth.a[0])
		return a[0]>oth.a[0];
		if(a[1]!=oth.a[1])
		return a[0]>oth.a[1];
		if(a[2]!=oth.a[2])
		return a[2]>oth.a[2];
		return sum>oth.sum;
	}
	void init(){
		memset(a,0,sizeof a);sum=0;
	}
	long long sum,a[3];
}dp[N][3],mmap[N];
void dfs(int step){
	if(step>n){
		long long ret=0;
		for(int i=1;i<=n;i++){
			ret+=ap[i][ap[i][0]];
		}
		ans=max(ans,ret);
		return;
	}
	if(ap[0][1]<m){
		ap[step][0]=1;
		ap[0][1]++;
		dfs(step+1);
		ap[0][1]--;
	}
	if(ap[0][2]<m){
		ap[step][0]=2;
		ap[0][2]++;
		dfs(step+1);
		ap[0][2]--;
	}
	if(ap[0][3]<m){
		ap[step][0]=3;
		ap[0][3]++;
		dfs(step+1);
		ap[0][3]--;
	}
}
void solve(){
	cin>>n;
	m=n/2;
	if(n<=30){
		ans=0;
		memset(ap,0,sizeof ap);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>ap[i][j];
		dfs(1);
		cout<<ans;
		return;
	}
	bool pd=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			dp[i][j].init();
			cin>>mmap[i].a[j];
			ap[i][j]=mmap[i].a[j];
			if(j!=1&&ap[i][j]!=0)pd=0;
		}
		mmap[i].sum=max({mmap[i].a[0],mmap[i].a[1],mmap[i].a[2]});
	}
	if(pd){
		for(int i=1;i<=n;i++){
			pps[i]=ap[i][1];
		}
		sort(pps+1,pps+n+1);
		for(int i=n;i>=n/2+1;i--)ans+=pps[i];
		cout<<ans;
		return;
	}
	sort(mmap+1,mmap+n+1);
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++){
			dp[i][j].sum=0;
			if(i==1){
				dp[1][j].sum=mmap[1].a[j];
				dp[1][j].a[0]=m;
				dp[1][j].a[1]=m;
				dp[1][j].a[2]=m;
				dp[1][j].a[j]=m-1;
			}
		}
	for(int i=2;i<=n;i++/*,puts("")*/)
		for(int j=0;j<3;j++){
			bool pd=0;
			int bi=i-1;
			for(int k=0;k<3;k++){
				if((dp[bi][k].a[j]>0)&&((dp[bi][k].sum+mmap[i].a[j])>dp[i][j].sum)){
					dp[i][j].sum=dp[bi][k].sum+mmap[i].a[j];
					dp[i][j].a[0]=dp[bi][k].a[0];
					dp[i][j].a[1]=dp[bi][k].a[1];
					dp[i][j].a[2]=dp[bi][k].a[2];
					dp[i][j].a[j]--;pd=1;
				}
			}
		
			if(!pd){
				int k=0,tmp=0;for(int kk=0;kk<2;kk++){if(dp[i-1][k].sum>tmp)k=kk,tmp;}
				dp[i][j].sum=dp[i-1][k].sum;
				dp[i][j].a[0]=dp[i-1][k].a[0];
				dp[i][j].a[1]=dp[i-1][k].a[1];
				dp[i][j].a[2]=dp[i-1][k].a[2];
			}
			//printf("%d(%d,%d,%d) ",dp[i][j].sum,dp[i][j].a[0],dp[i][j].a[1],dp[i][j].a[2]);
		}
	cout<<max(dp[n][0].sum,max(dp[n][1].sum,dp[n][2].sum))<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}
/*
history:
	14:30 begin,see 4 problems(there's a graph and a string problem)
	14:50 think T1 is a DP,try to solve it.
	15:00 get the idea,write code
	15:30 ok
	15:40 debug no
	17:30 debug still no goto T2
	17:40 T2 have 20pts [555]
	18:00-18::25 T3:0 T4:20 T1:45 T2:20
	end of it, //free //freopen //freowen
*/
