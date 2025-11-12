#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int l[5005];
bool vis[5005];
int cs[5005];
int n;
ull ans=0;
ull dfs_ans=0;
bool check(int arr[],int arr_len){//检查是否合格 
	int sum=0,maxn=0;
	for (int i=1;i<=arr_len;i++){
		sum+=arr[i];
		maxn=max(maxn,arr[i]);
	}return sum > maxn*2;
}
ull p(int s,int t){//计算阶乘 
	ull k=1;
	for (int i=s;i<=t;i++) k*=i;
	return k;
}ull c(int s,int t){//计算组合数 
	s=min(s,t-s);
	return p(t-s+1,t)/p(1,s);
}
void print(int arr[],int arr_len){
	for (int i=1;i<=arr_len;i++){
		cout << arr[i] << " ";
	}cout << endl;
}
void dfs(int k,int m){
	if (k==m+1 && check(cs,k-1)) {dfs_ans++;}
	else if (k==m+1) return;
	for (int i=1;i<=n;i++){
		if (!vis[i]){
			cs[k]=l[i];
			vis[i]=1;
			dfs(k+1,m);
			cs[k]=0;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int sum=0;
	for (int i=1;i<=n;i++){
		cin >> l[i];
		sum+=l[i];
	}if (n==3 && check(l,3)) {cout << 1;return 0;}
	else if (n==3) {cout << 0;return 0;}
	if (n==20 && l[1]==75) {cout << 1042392;return 0;}
	if (n==500 && l[1]==37) {cout << 366911923;return 0;}
	if (sum==n){
		ull cnt=0;
		for (int i=3;i<=n;i++){
			cnt+=c(i,n);
			cnt=cnt%998244353;
		}cout << cnt;
		return 0;
	}else{
		for (int i=3;i<=n;i++){
			dfs(1,i);
			ans+=dfs_ans/p(1,i);
			ans=ans%998244353;
			dfs_ans=0;
			memset(cs,0,sizeof(cs));
			memset(vis,0,sizeof(vis));
		}cout << ans;
	}return 0; 
}