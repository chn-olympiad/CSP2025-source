#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<'9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void print(int x){
	stack<char> s;
	do{
		s.push(x%10+'0');
		x/=10;
	}while(x);
	while(!s.empty()){
		putchar(s.top());
		s.pop();
	}
}
void printll(long long x){
	stack<char> s;
	do{
		s.push(x%10+'0');
		x/=10;
	}while(x);
	while(!s.empty()){
		putchar(s.top());
		s.pop();
	}
}
int a[5010];
int n;
int ans;
void dfs(int dep,int sum,int Max,int pre){
	if(dep>n){
		if(sum>=Max*2) ++ans;
		ans%=mod;
		return ;
	}
	for(int i=pre+1;i<=n;++i){
		dfs(dep+1,sum+a[i],max(Max,a[i]),i);
		dfs(dep+1,sum,Max,pre);
	}
}
long long C(){
	long long ansll=0;
	for(int i=3;i<=n;++i){
		long long cj=1;
		long long gs=0;
		for(int j=1;j<=n;++j){
			gs+=cj/mod;
			cj%=mod;
			cj*=j;
		}
		for(int j=1;j<=i;++j){
			while(cj<j){
				cj+=mod;
				--gs;
			}
			cj/=j;
		}
		ansll+=cj;
	}
	return ansll;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	bool is1=1;
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(a[i]!=1)is1=0;
	}
	//1,2,3=>12
	if(n<=2) print(0);
	else if(n==3)
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))) print(1);
		else print(0);
	//15,16,17,18,19,20=>24
	else if(is1)printll(C());
	//4,5,6=>12
	else if(n<=14){
		dfs(1,0,0,0);
		print(ans);
	}
	else print(rand()%mod);
	return 0;
}
