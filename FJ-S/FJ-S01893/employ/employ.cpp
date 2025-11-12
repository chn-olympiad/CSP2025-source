#include<bits/stdc++.h>
#define ulp(i,a,b) for(int i=a;i<=b;i++)
#define dlp(i,a,b) for(int i=a;i>=b;i--)
#define inf 0x3f3f3f3f
//#define int long long
#define il inline
#define push_back pb
#define pii pair<int,int>
#define hh putchar('\n')
#define kg putchar(' ')
#define fir first
#define sec second
#define lowbit ((i)&(-i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
il int read(){
	int num=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=1;
		c=getchar();
	}
	while(isdigit(c)){
		num=(num<<3)+(num<<1)+(c^48);
		c=getchar();
	}
	return f?-num:num;
}
il void write(int x){
	if(x<0)putchar('-'),x=-x;
	int stk[50],top=0;
	do{
		stk[++top]=x%10;
		x/=10;
	}while(x);
	dlp(i,top,1)putchar(stk[i]+'0');
}
il char rdc(){
	char c=getchar();
	while(c==' '||c=='\n')c=getchar();
	return c;
}
int n,m;
int c[225];
int s[225];
int ms[225]; 
int hanser=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	ulp(i,1,n)s[i]=(rdc()=='1');
	ulp(i,1,n)c[i]=read();
//	ulp(i,1,n)write(c[i]),kg;
//	ulp(i,1,n)write(s[i]),kg;
	ulp(i,1,n)ms[i]=i;
	do{
		int failed=0,ok=0;
		ulp(i,1,n){
			if(!s[i]){
				//cout<<i<<':'<<"it's too difficult!"<<endl;
				failed++;
			}
			else if(failed>=c[ms[i]]){
				//cout<<i<<':'<<"I have no egg!"<<endl;
				//cout<<failed<<'>'<<'='<<c[i]<<endl;
				++failed;
			}
			else ok++;
			
		}
		//write(ok),hh;
		if(ok>=m){
			++hanser;
//			ulp(i,1,n)write(ms[i]),kg;
//			hh;
		}
	}
	while(next_permutation(ms+1,ms+n+1));
		//ulp(i,1,n)write(ms[i]),kg;
		
	write(hanser);
	return 0;
} 
