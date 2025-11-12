#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n,t,a[N][5],ans;
void dfs(int x,int sum1,int sum2,int sum3,int num1,int num2,int num3){
	//cout<<x<<endl;
	if(x==n+1){
		ans=max(ans,sum1+sum2+sum3);
		return;
	}
	if(num1<n/2){
		dfs(x+1,sum1+a[x][1],sum2,sum3,num1+1,num2,num3);
	}
	if(num2<n/2){
		dfs(x+1,sum1,sum2+a[x][2],sum3,num1,num2+1,num3);
	}
	if(num3<n/2){
		dfs(x+1,sum1,sum2,sum3+a[x][3],num1,num2,num3+1);
	}
	dfs(x+1,sum1,sum2,sum3,num1,num2,num3);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club3.in","r",stdin);
//	freopen("club3.out","w",stdout);
	cin>>t;
	while(t--){
		ans=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0,0,0,0,0,0);
		cout<<ans<<endl;
	}
	
	
	
	
	
	

	return 0;
}
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
