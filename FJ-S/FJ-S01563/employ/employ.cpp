#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
const int MAXN=500+5;
int n,m,c[MAXN];
char s[MAXN];
bool vis[MAXN];

char gc(){return getchar();}
void pc(char c){putchar(c);}

void read(int &x){
	char c; bool f=false;
	for(;!isdigit(c=getchar());)
		if(c=='-') f=true;
	for(x=c-'0';isdigit(c=getchar());)
		x=x*10+c-'0';
	if(f) x=-x;
}

void write(int x){
	if(x==0){pc('0');return;}
	if(x<0){pc('-');x=-x;}
	char s[20]; int k=0;
	for(;x;x/=10) s[k++]=x%10+'0';
	for(;k--;) pc(s[k]);
}

void input(){
	read(n),read(m);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i) read(c[i]);
}

int fac(int n){
	int res=1;
	for(int i=1;i<=n;++i) res=1ll*res*i%mod;
	return res;
}

void dfs(int i,int k,int &ans){
	if(i-k>=m) ans=(1ll*ans+fac(n-i+1))%mod;
	if(i==n+1||n-k<m) return;
	for(int j=1;j<=n;++j){
		if(!vis[j]){
			vis[j]=true;
			if(s[i]=='0'||k>=c[j]) dfs(i+1,k+1,ans);
			else dfs(i+1,k,ans);
			vis[j]=false;
		}
	}
}

void baoli(){//20pts
	int ans=0;
	dfs(1,0,ans);
	write(ans);
}

bool checkA(){
	for(int i=1;i<=n;++i){
		if(s[i]!='1') return false;
	}
	return true;
}

void solveA(){
	int ans=0,k=0,x=501;
	for(int i=1;i<=n;++i) if(c[i]==0) ++k;
	for(int i=1;i<=n;++i)
	if(n-k<m) ans=0;
	else ans=fac(n);
	write(ans);
}

void solve(){
	
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	input();/*
	if(checkA()) solveA();
	else if(n<=10) baoli();
	else solve();*/
	baoli();
	return 0;
}
