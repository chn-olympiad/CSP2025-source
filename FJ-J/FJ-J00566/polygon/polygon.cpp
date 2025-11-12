#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[10000],t;long long anst;
bool f[10000],A=1;
int dfs(int q,int l,int num){
	int ans=0;
	for(int i=l+1;i<t;i++){
		f[i]=1;
		ans+=dfs(q+1,i,num+a[i]);
		if(q>1 && (num+a[i])>a[t]) ans++;
		f[i]=0;
	}
	return ans;
}
int chengji(int x){
	long long o=1;
	for(int i=n;i>=n-x+1;i--){
		o*=i;
	}
	for(int i=1;i<=x;i++){
		o/=i;
	}
	return o%N;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) A=0;
	}
	if(A){
		for(int i=3;i<n;i++){
			int x=min(i,n-i);
			anst+=chengji(x);
			anst%=N;
		}
		anst++;
		cout<<anst;return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		t=i;
		anst+=dfs(1,0,0);
		anst%=N;
	}
	cout<<anst;
	return 0;
}
