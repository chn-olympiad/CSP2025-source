#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int li[N][3];
int ans;
int n;
void dfs(int step,int a,int b,int c,int sum){
//	cout<<step<<' '<<a<<' '<<b<<' '<<c<<' '<<sum<<endl;
	if (step>n){
		ans=max(ans,sum);
		return ;
	}
	if (a+1>n/2){
		dfs(step+1,a,b+1,c,sum+li[step][1]);
		dfs(step+1,a,b,c+1,sum+li[step][2]);
	}
	else if (b+1>n/2){
		dfs(step+1,a+1,b,c,sum+li[step][0]);
		dfs(step+1,a,b,c+1,sum+li[step][2]);
	}
	else if (c+1>n/2){
		dfs(step+1,a,b+1,c,sum+li[step][1]);
		dfs(step+1,a+1,b,c,sum+li[step][0]);
	}
	else{
		dfs(step+1,a+1,b,c,sum+li[step][0]);
		dfs(step+1,a,b+1,c,sum+li[step][1]);
		dfs(step+1,a,b,c+1,sum+li[step][2]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while (T--){
//		int n;
		cin>>n;
//		cout<<n<<endl;
		for (int i=1;i<=n;i++){
			cin>>li[i][0]>>li[i][1]>>li[i][2];
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
