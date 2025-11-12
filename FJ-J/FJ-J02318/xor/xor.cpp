#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,o;
int a[N],p[N];
int dp[N];
int ans;
struct node{
	int l,r;
}b[N];
bool cmp(node x,node y){
	if(x.l==y.l)return x.r<y.r;
	return x.l<y.l;
}
int dfs(int k,int cnt){
	if(cnt==m){
		return k-1;
	}
	if(k>n){
		return 0;
	}
	return dfs(k+1,a[k]^cnt);
}
bool pd(int l1,int r1,int l2,int r2){
	if(l2<=r1&&r2>=r1){
//		cout<<1<<' ';
		return 0;
	}
	if(l1<=r2&&r1>=r2){
//		cout<<2<<' ';
		return 0;
	}
	if(l2<=l1&&r2>=l1){
//		cout<<3<<' ';
		return 0;
	}
	if(l1<=l2&&r1>=l2){
//		cout<<4<<' ';
		return 0;
	}
	return 1;
}
int find(int x){
	int maxx=1;
	int u=b[x].l,v=b[x].r;
	for(int i=x+1;i<=o;i++){
		if(pd(u,v,b[i].l,b[i].r)){
//			cout<<find(i)<<endl;
//			maxx=max(find(i)+1,maxx);
			maxx=max(dp[i]+1,maxx);
		}
	}
	return maxx;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=dfs(i+1,a[i]);
		if(x){
			o++;
			b[o].l=i;
			b[o].r=x;
//			cout<<i<<' '<<x<<endl;
		}
	}
	sort(b+1,b+o+1,cmp);
//	cout<<pd(1,2,4,4)<<endl;
//	for(int i=1;i<=o;i++){
////		cout<<b[i].l<<' '<<b[i].r<<endl;
//		int x=find(i);
//		ans=max(x,ans);
//	}
	for(int i=o;i>=1;i--){
		int x=find(i);
		dp[i]=x;
		ans=max(x,ans);
	}
	cout<<ans;
	return 0;
} 
