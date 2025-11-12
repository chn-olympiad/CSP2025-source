#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long a=0;
	short b=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') b=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<3)+(a<<1)+c-48;
		c=getchar();
	}
	return a*b;
}
const int mod=998244353;
int ac[5005],ak[5005],n;
inline int dfs(int d,int c,int h,int mx){
	if(d>n){
		if(mx*2<h) return 1;
		return 0;
	}
	if(n-d+1+c==3) return dfs(d+1,c+1,h+ac[d],ac[d])%mod;
	return (dfs(d+1,c+1,h+ac[d],ac[d])+dfs(d+1,c,h,mx))%mod;
}
main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) ac[i]=read();
	sort(ac+1,ac+n+1);
	cout <<dfs(1,0,0,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}