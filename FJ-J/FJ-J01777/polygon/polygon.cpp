#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e3+5;
const int MAX=1<<20;
int n,a[MAXN];
int f[MAX];
bool vis[MAXN];

char gc(){return getchar();}
void pc(char c){putchar(c);}

void read(int &x){
	char c; bool f=false;
	for(;!isdigit(c=gc());)
		if(c=='-') f=true;
	for(x=c-'0';isdigit(c=gc());)
		x=x*10+c-'0';
	if(f) x=-x;
}

void write(int x){
	if(x==0){pc('0');return;}
	if(x<0){pc('-');x=-x;}
	char s[20]; int len=0;
	for(;x;x/=10) s[len++]=x%10+'0';
	for(;len--;) pc(s[len]);
}

void input(){
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	sort(a+1,a+n+1);
}

bool check1(){
	return n<=20;
}

void dfs(int i,int sum,int maxn,int &ans){
	if(i==n+1){
		if(sum-maxn>maxn) ++ans;
		return;
	}
	dfs(i+1,sum+a[i],a[i],ans);
	dfs(i+1,sum,maxn,ans);
}

void solve1(){ //O(2^n)
	int ans=0;
	dfs(1,0,0,ans);
	write(ans);
}

void solve2(){
	
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	input();
	if(check1()) solve1();
	else solve2();
	return 0;
}
