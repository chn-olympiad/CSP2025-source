//45
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N=10005;
int n;
int a[N],b[N],c[N];
int ans; 
void dfs(int ac,int bc,int cc,int val,int pos){
	if(ac+bc+cc==n){
		ans=max(ans,val);
	}
	if(ac<n/2){
		dfs(ac+1,bc,cc,val+a[pos+1],pos+1);
	}
	if(bc<n/2){
		dfs(ac,bc+1,cc,val+b[pos+1],pos+1);
	}
	if(cc<n/2){
		dfs(ac,bc,cc+1,val+c[pos+1],pos+1);
	}
}
void solve(){
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	if(n<=30){
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
	}else{
		sort(a+1,a+1+n);
		for(int i=n;i>n/2;i--){
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
