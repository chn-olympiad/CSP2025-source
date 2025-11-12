#include <iostream>
#include <cstring>
using namespace std;
void fropen(string name){
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}
namespace ForceSolve{
	//20pts
	int mydmx=0;
	int n;
	const int N=1e5;
	int a[N+9][4];
	void dfs(int x,int sum,int a1,int a2,int a3){
		if(x==n+1){
			mydmx=max(sum,mydmx);
		}
		if(a1+1<=n/2)dfs(x+1,sum+a[x][1],a1+1,a2,a3);
		if(a2+1<=n/2)dfs(x+1,sum+a[x][2],a1,a2+1,a3);
		if(a3+1<=n/2)dfs(x+1,sum+a[x][3],a1,a2,a3+1);
	}
	void Main(){
		mydmx=0;
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(1,0,0,0,0);
		cout<<mydmx<<endl; 
	} 
}
namespace DPsolve1{
	//0pts!It's wrong!
	const int N=1e5;
	int a[N+9][4];
	struct node{
		int myd;
		int s[4];
	} dp[N+9][4];
	void Main(){
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				node mx;
				memset(&mx,0,sizeof(mx));
				for(int k=0;k<i;k++){
					for(int l=1;l<=3;l++){
						if(dp[k][l].s[j]+1<=n/2){
							if(dp[k][l].myd+a[i][j]>mx.myd){
								mx.myd=dp[k][l].myd+a[i][j];
								for(int m=1;m<=3;m++){
									mx.s[m]=dp[k][l].s[m];
									if(m==j)mx.s[m]=dp[k][l].s[m]+1;
								}
							}
						}
					}
				}
				dp[i][j]=mx;
			}
		}
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cerr<<dp[i][j].myd<<' ';
			}
			cerr<<endl;
		}
		for(int i=1;i<=3;i++){
			maxn=max(maxn,dp[n][i].myd);
		}
		cout<<maxn<<endl;
	} 
}

using namespace ForceSolve;
int main(){
	fropen("club");
	int t;
	cin>>t;
	while(t--){
		Main(); 
	}
	return 0;
}

