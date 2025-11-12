#include<bits/stdc++.h>
#define int long long 
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
int n,m,a[105],ac,ak,ans,ans2;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n*m;i++) cin>>a[i];
	ac=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ac) ak=i;
	}	
	if(ak%m==0) ans=ak/n;
	else ans=ak/n+1;
	if(ans%2==1){
		int l=ak-(ans-1)*n;
		ans2=l;
	}else{
		int l=ak-(ans-1)*n;
		ans2=m-l+1;
	}
	write(ans);
	printf(" ");
	write(ans2);
	return 0;
}
