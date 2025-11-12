#include<bits/stdc++.h>
using namespace std;

const int N=5e5;
int t,n,x[N],y[N],z[N],len;
long long ans=0;

inline void read(int &n,int ch=0,bool t=0){
	n=0;
	while(!isdigit(ch=getchar()))if(ch=='-')t=1;
	for(;isdigit(ch);ch=getchar())n=(n<<3)+(n<<1)+(ch^48);
	if(t)n=-n;
}

void dfs(int k,long long sum,int a,int b,int c){
	if(k>n){
		ans=max(ans,sum);
		return;
	}
	if(a+1<=len)dfs(k+1,sum+x[k],a+1,b,c);
	if(b+1<=len)dfs(k+1,sum+y[k],a,b+1,c);
	if(c+1<=len)dfs(k+1,sum+z[k],a,b,c+1);
}
void out(int n){
	if(!n)return ;
	out(n/10);
	putchar(n%10+48);
}
void put(int n){
	if(n==0){putchar('0');return;}
	if(n<0)putchar('-'),n=-n;
	out(n);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++)
			read(x[i]),read(y[i]),read(z[i]);
		ans=0;
		len=n>>1;
		dfs(1,0,0,0,0);
		put(ans);
		putchar('\n');
	}
	return 0;
}
