#include<bits/stdc++.h>
using namespace std;
const int N=1<<21;
char in[N],*p1=in,*p2=in,out[N],*op=out;
inline char gc(){
	return p1==p2&&(p2=(p1=in)+fread(in,1,N,stdin),p1==p2)?EOF:*p1++; 
}
template<typename T>
inline void read(T &x){
	char c=gc();
	while(!isdigit(c)) c=gc();
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c-'0');
		c=gc();
	}
}
inline void flush(){
	fwrite(out,1,op-out,stdout);
	op=out;
}
template<typename T>
inline void write(T x){
	if(x>9) write(x/10);
	if(op-out>=N-20) flush();
	*op++=x%10+'0';
}
const int mod=998244353; 
long long n,a[5010],f[5010];
unsigned long long ans;
bool vis[5010];
void dfs(int i,int t,long long ma,long long sum){
	ans=(ans+1)%mod;
	for(int j=i;j<=t;j++){
		if(!vis[j]&&sum-a[j]>ma){
			vis[j]=true;
			dfs(j,t,ma,sum-a[j]);
			vis[j]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
		if(i>=3&&f[i-1]>a[i]){
			dfs(1,i-1,a[i],f[i-1]);
		}
	}
	write(ans);
	flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
