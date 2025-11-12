#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ulp(i,f,n) for(long long i=f;i<=n;i++) 
#define dlp(i,a,b) for(long long i=a;i>=b;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define pb push_back
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!('0'<=c&&c<='9')){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
int n,m,a,k=1,t;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read(),a=read();
	ulp(i,2,n*m){
		t=read();
		if(t>a) k++;
	}
	int ans1=ceil(k*1.0/n);
	int ans2=(ans1&1?k-n*(ans1-1):n+1-k+n*(ans1-1));
	write(ans1),putchar(' '),write(ans2);
	return 0;
}
