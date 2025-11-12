 #include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[10100],l,i,j,n,m,x,k,t,ans,sum;
bool check(ll x,ll y){
	if(x>y*2) return 1;
	return 0;
}
void dfs(ll x,ll sum,ll m){
	if(x>n){
		if(check(sum,m)) ans++;
		return ;
	}
  	dfs(x+1,sum,m);
	dfs(x+1,sum+a[x],max(m,a[x]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3) return cout<<0,0;
	if(n==3){
		for(i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
			m=max(m,a[i]);
		}
		if(check(sum,m)) cout<<1;
		else cout<<0;
		return 0;
	}
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=1) t++;
	} 
	if(t==n){
		l=n-2;
		for(i=1;l>=1;i++){
			ans+=l*i;
			l--;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
} 
