#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
template<class...Arg>
void println(Arg...arg){
	int _[]={(cout<<arg<<' ',0)...};
	cout<<'\n';
}
int t;
//struct Stu{
//	int a,i;
//	bool operator<(const Stu& t)const{
//		return a<t.a;
//	}	
//	bool operator>(const Stu& t)const{
//		return a>t.a;
//	}
//}
int stu[100005][3];
int tstu[100005];
struct Trans{
	int f,t,maxn;
	bool operator<(const Trans& t)const{
		return maxn<t.maxn;
	}
	bool operator>(const Trans& t)const{
		return maxn>t.maxn;
	}
};
int dp[205][205][205];
//void dfs(int i,int a,int b,int c,int t){
//	if(i==n)
//	for(int j=0;j<3;j++)
//	dfs(i+1,a+1,b+1,c+1,t+stu[i][j]);
//}
int main() {
	//freopen("../../csps/club/club.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(dp,0,sizeof dp);
		int n;
		cin>>n;
		int a,b,c;
		bool xa=true,xb=true;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			stu[i][0]=a;stu[i][1]=b;stu[i][2]=c;
			if(b!=0||c!=0) xa=false;
		}
//		priority_queue<Trans,vector<Trans>,greater<Trans>> que;
//		for(int i=1;i<=n;i++){
//			cin>>a>>b>>c;
//			
//			sort(stu[i],stu[i]+3,greater<Stu>());
//			que.push({stu[i][0].i,stu[i][1].i,abs(stu[i][0].a-stu[i][1].a)});
//		}
//		int box[4]={0,0,0,0};
//		int ans=0;
//		for(int i=1;i<=n;i++){
//			//println("asd");
//			if(box[stu[i][0].i]+1<=n/2){
//				ans+=stu[i][0].a;
//				++box[stu[i][0].i];
//			}else{
//				//println("as",que.top().maxn);
//				if(!que.empty()&&stu[i][0].a>=que.top().maxn){
//					ans+=-que.top().maxn+stu[i][0].a;
//					que.pop();
//				}
//			}
//			//println(i,ans);
//		}
//		
////		for(int i=1;i<=n;i++){
//			for(int m=0;m<3;m++){
//				dp[i][m]=max(dp[i-1][0],dp[])
//			}
//			
//		}
//		for(int i=1;i<=n;i++){			
//			for(int cho=0;cho<3;cho++){
//				int oa,ob;
//				if(cho==0) oa=1,ob=2;
//				if(cho==1) oa=0,ob=2;
//				if(cho==2) oa=0,ob=1;
//				dp[cho][0]=max(dp[oa][n/2],dp[ob][n/2]);
//				for(int j=max(1,i-n/2);j<=min(i,n/2);j++){
//					//dp[cho][0]=max(dp[oa][j],dp[ob][i-j]);
//				}
//				//println("as",i,cho,0,dp[cho][0]);
//			}
//			for(int cho=0;cho<3;cho++)
//			for(int s=n/2;s>=1;s--){
//				dp[cho][s]=max(dp[cho][s],dp[cho][s-1]+stu[i][cho]);
//				println(i,cho,s,dp[cho][s]);
//				ans=max(ans,dp[cho][s]);	
//			}
//		}
		if(xa){
			for(int i=1;i<=n;i++){
				tstu[i]=stu[i][0];
			}
			sort(tstu+1,tstu+n,greater<int>());
			int ans=0;
			for(int i=1;i<=n/2;i++) ans+=tstu[i];
			cout<<ans<<'\n';
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(a=0;a<=min(n/2,i);a++){
				for(b=0;b<=n/2&&a+b<=i;b++){
					int c=i-a-b;
					if(c>n/2) continue;
					//int ha=a%3,hb=b%3,hc=c%3,ua=(a-1)%3,ub=(b-1)%3,uc=(c-1)%3;
					if(a>0)
					dp[a][b][c]=max(dp[a][b][c],dp[a-1][b][c]+stu[i][0]);
					if(b>0)
					dp[a][b][c]=max(dp[a][b][c],dp[a][b-1][c]+stu[i][1]);
					if(c>0)
					dp[a][b][c]=max(dp[a][b][c],dp[a][b][c-1]+stu[i][2]);
					//println(a,b,c,dp[a][b][c]);
					ans=max(ans,dp[a][b][c]);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
