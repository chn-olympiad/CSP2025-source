#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int T;
int n;
int ans;
int a[N+23][4];
void dfs(int pos,int num1,int num2,int num3,int sum){
	if(pos>n){
		ans=max(ans,sum);
		return;	
	}
	if(num1<n/2)	dfs(pos+1,num1+1,num2,num3,sum+a[pos][1]);
	if(num2<n/2)	dfs(pos+1,num1,num2+1,num3,sum+a[pos][2]);
	if(num3<n/2)	dfs(pos+1,num1,num2,num3+1,sum+a[pos][3]);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
