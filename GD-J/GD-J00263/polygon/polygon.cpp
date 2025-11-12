#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int mod=998244353;
int n,m;
int maxx=0;
int ans;
int a[N];
unsigned long long c[N][N];
void get_c(int n){
	c[0][0]=c[1][0]=c[1][1]=1;
//	cout<<1<<"\n1 1\n"; 
	for(int i=2;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(j==0||j==i) c[i][j]=1;
			else c[i][j]=c[i-1][j]+c[i-1][j-1];
			c[i][j]=c[i][j]%mod;
//			cout<<c[i][j]<<" ";
		}
//		cout<<endl;
	}
}
void dfs(int x,int sum,int maxx){
	if(x==n+1){
//		cout<<sum<<endl;
		if(sum>maxx*2) ans++;
		ans=ans%mod;
		return;
	}else{
//		if(sum>maxx*2) ans++;
//		cout<<1<<" "<<sum<<"->"<<" ";
		dfs(x+1,sum+a[x],a[x]);
//		cout<<endl;
//		cout<<0<<" "<<sum<<"->"<<" ";
		dfs(x+1,sum,maxx);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	if(maxx!=1) dfs(1,0,a[1]);
	else{
		get_c(n);
//		for(int i=0;i<=n;i++){
//			for(int j=0;j<=i;j++){
//				cout<<i<<","<<j<<","<<c[i][j]<<" ";
//			}
//			cout<<endl;
//		} 
		for(int i=3;i<=n;i++) {
			ans+=c[n][i];
			
		}
	}
	cout<<ans;
	return 0;
}
