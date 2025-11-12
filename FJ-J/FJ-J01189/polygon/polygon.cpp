#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;	
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
	return;
}
int n,k,a[100005],cnt2;
bool pd=true;
void dfs(int maxx,int cnt,int ac,int ids){
	if(ac==0){
		if(cnt>maxx*2){
		//	write(maxx);
		//	printf(" ");
		//	write(cnt);
		//	printf("\n");
			cnt2++;
			cnt%=998244353;
		}
		return;
	}
	for(int i=ids;i<=n;i++){
		dfs(max(maxx,a[i]),cnt+a[i],ac-1,i+1);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]>1) pd=false;
	}
	if(pd){
		write((1+n-2)*(n-2)/2);
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(-4231,0,i,1);	
	}
	write(cnt2);
	return 0;
}
/*
(1+n-2)*(n-2)/2;

*/
