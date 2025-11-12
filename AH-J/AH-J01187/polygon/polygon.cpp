#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10, MOD=998244353;
int n, m, a[N], dp[N], ans, pot;
int read(){
	int s=0, f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+(ch&15);
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0) x=-x, putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n=read();
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	if(n==3){
		int x=a[1], y=a[2], z=a[3];
		if(x+y>z||x+z>y||y+z>x) cout<<1<<endl;
		else cout<<0<<endl;
	}
	else{
		dp[1]=dp[2]=0;
		for(int i=1; i<=n; i++){
			dp[i]=max(dp[i-1], (dp[i-1]+a[i])%MOD)%MOD;
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
