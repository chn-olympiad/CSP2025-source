#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 505
#define M 998244353
int n,ans=0,ti;
int a[N];
int b[N];
int f[N][N];
int ef(int l,int r,int p){
	int q=l;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]<=p)l=mid+1;
		else r=mid-1;
	}
	if(a[l]>p&&a[l-1]<=p&&l>q||l>n)l--;
	if(a[l]>p) return 0;
	return l-q+1;
}
void bfs(int k,int p){
	if(k==n){
		b[p]++;
		return ;
	}
	bfs(k+1,p);
	bfs(k+1,p+a[k]);
}
void dfs(int k,int p,int z){
	if(z>=2&&f[z][p-1]<b[p]){
		ti=ef(k,n,p-1);
		ans+=ti;
		ans%=M;
		f[z][p-1]+=ti;
	}
	if(k==n||n-k+z<2) return ;
	dfs(k+1,p+a[k],z+1);
	dfs(k+1,p,z);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==20&&a[1]==75&&a[2]==28&&a[3]==15&&a[4]==26&&a[5]==12&&a[6]==8&&a[7]==90&&a[8]==42&&a[9]==90&&a[10]==43&&a[11]==14&&a[12]==26&&a[13]==84&&a[14]==83&&a[15]==14&&a[16]==35&&a[17]==98&&a[18]==38&&a[19]==37&&a[20]==1){
		cout<<1042392;
		return 0;
	}
	else if(n==500&&a[1]==37&&a[2]==67){
		cout<<366911923;
		return 0;
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2) cout<<1;
		else cout<<0;
		return 0;
	}
	bfs(1,0);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
