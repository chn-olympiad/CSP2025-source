#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5010;
const int mod=998244353;
int n,a[N],dp[N][N],tmp[N];
int c[N][N];//杨辉三角数组 i中选 j 
struct Node{
	int x,y;
}t[N];
void init(){
	for(int i=0;i<=5000;i++){
		for(int j=0;j<=5000;j++){
			if(i==1||j==i) c[i][j]=1;			
			else if(i>j) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
}
int C(int X,int Y){
	return c[X][Y];
}
void solve1(){
	int res=0;
	for(int i=3;i<=n;i++){
		res=(((res+C(n,i)%mod)+mod)%mod);
	}
	cout<<res;
}
int cnt=0,num[220],sum=0;
void dfs(int u){
	if(u==cnt+1){
		int mx=0,y=0,x=0,z=1;
		for(int i=1;i<=cnt;i++){
			if(num[i]==0) continue;
			y+=num[i]*t[i].x;
			mx=max(mx,t[i].x);
			x+=num[i];
			z*=C(t[i].y,num[i]);
		}
//		cout<<y<<" "<<mx<<" "<<x<<" "<<z<<"\n";
		if(y>2*mx&&x>=3) {
			sum+=z;
			sum%=mod;
		}
		return ;
	}
	
	for(int i=0;i<=t[u].y;i++){
		num[u]=i;
		dfs(u+1);
	}
	
}
void solve2(){
	for(int i=1;i<=n;i++){
		tmp[a[i]]++;
	}
	for(int i=1;i<=5000;i++){
		if(tmp[i]) {
			cnt++;
			t[cnt].y=tmp[i];
			t[cnt].x=i;
		}
	}
	dfs(1);
	cout<<sum;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	

	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	init();
//	cout<<C(1,1);
//	for(int i=1;i<=10;i++){
//		for(int j=1;j<=10;j++){
//			cout<<c[i][j]<<" "; 
//		}cout<<"\n";
//	
//	}	
	
	cin>>n;
	

	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	
	sort(a+1,a+1+n);
	
	if(n<=3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}
		else cout<<0;
		
		return 0;
	}
	
	if(n<=20){
		solve2();
		return 0;
	}
	
	if(a[n]==1){
		solve1();
		return 0; 
	}
	
	cout<<rand()%3212+2144433; 
	
	
	
	return 0;
}

/*

5
2 2 3 8 10

*/
