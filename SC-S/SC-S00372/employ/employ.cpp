#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
int const N=5e2+1;
bitset<N> bt;
char S[N];
int c[N];
bool flag=1;
long long ans=0;
int n,m,len=0;
long long read(){
	char ch=getchar();
	long long res=0;
	int f=1;
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
void print(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		print(x/10);
	}
	putchar((x%10)^48);
}
void read_str(char (&S)[N]){
	char ch=getchar();
	while(!isdigit(ch)){
		ch=getchar();
	}
	while(isdigit(ch)){
		S[len++]=ch;
		ch=getchar();
	}
}
void dfs(int pos,int now){
	if(pos==n){
		ans+=(n-now>=m);
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!bt[i]){
			bt.set(i);
			if(c[i]<=now){
				dfs(pos+1,now+1);
			}
			else{
				if(S[pos]=='0'){
					dfs(pos+1,now+1);
				}
				else if(S[pos]=='1'){
					dfs(pos+1,now);
				}
			}
			bt.reset(i);
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	read_str(S);
	for(int i=0;i<n;i++){
		if(S[i]=='0'){
			flag=0;
		}
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	if(flag){
		ans=1;
		for(int i=2;i<=n;i++){
			ans=(ans*i)%mod;
		}
	}
	else if(m==n){
		ans=0;
	}
	else{
		dfs(0,0);
	}
	print(ans);
	return 0;
}
/*
3 2
101
1 1 2
*/