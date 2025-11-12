#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,a[maxn][5],b[maxn],A,B,C,ans=0;
void dfs(int t,int sum){
	if(A>n/2&&B>n/2&&C>n/2)return;
	if(t>n){
		if(A<=n/2&&B<=n/2&&C<=n/2){
			ans=max(ans,sum);
		}
		return;
	}
	A++;
	dfs(t+1,sum+a[t][1]);
	A--;
	B++;
	dfs(t+1,sum+a[t][2]);
	B--;
	C++;
	dfs(t+1,sum+a[t][3]);
	C--;
	return;
}
void solve(){
	ans=0;
	cin>>n;
	int f1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]+a[i][3]!=0)f1=0;
	}
	if(n<=10){
		dfs(1,0);
		cout<<ans<<'\n';
	}else if(f1==1){
		for(int i=1;i<=n;i++){
			b[i]=a[i][1];
		}
		sort(b+1,b+1+n);
		for(int i=n;i>=(n/2)+1;i--){
			ans+=b[i];
		}
		cout<<ans<<'\n';
	}else{
		for(int i=1;i<=n;i++){
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
//long long ·¶Î§ 25pts
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
