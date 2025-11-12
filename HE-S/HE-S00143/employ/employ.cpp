#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>10){
		write(x/10);
	}
	putchar(x%10+'0');
	return ;
}
const int mod=998244353;
int n,m;
bitset <505> b;
int c[505];
int f[505];
int jc[505];
int b_dfs(int x,int y){
//	cout<<x<<" "<<y<<endl;
	if(y>=m){
		return jc[n-x+1];
	}
	if(m-y>n-x+1){
		return 0;
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(f[i]){
			continue;
		}
		f[i]=1;
		if(x-1-y>=c[i]||b[x-1]==0){
			res+=b_dfs(x+1,y);
		}else{
			res+=b_dfs(x+1,y+1);
		}
		res%=mod;
		f[i]=0;
	}
	return res;
}
void baoli(){
	write(b_dfs(1,0));
	return ;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	jc[0]=1;
	for(int i=1;i<=500;i++){
		jc[i]=jc[i-1]*i%mod;
//		cout<<i<<" "<<jc[i]<<endl;
	}
	n=read();
	m=read();
	cin>>b;
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(b[i]==1){
			cnt++;
		}
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
//	if(A){
//		cout<<jc[n];
//		return 0;
//	}
	if(m==n){
		for(int i=0;i<n;i++){
			if(b[i]==0||c[i+1]==0){
				cout<<0;
				return 0;
			}
		}
		cout<<jc[n];
		return 0;
	}
	baoli();
	return 0;
}
