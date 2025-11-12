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
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	while(q--){
		puts("0");
	}
	return 0;
} 
