#include<bits/stdc++.h>
#define ulp(i,a,b) for(int i=a;i<=b;++i)
#define dlp(i,a,b) for(int i=a;i>=b;--i)
#define pii pair<int,int> 
#define push_back push_back
#define fir first
#define sed second
#define il inline
#define hh putchar('\n')
#define kg putchar(' ')
#define lowbit(i) (i&(-i))

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
#define N 15
int n,m;
int a[N*N],s;
void work(int x){
	int op=0;
	while(x>n){
		++op;
		x-=n;
	}
	write(op+1),kg;
	if(op&1){
		write(n-x+1);
	}
	else write(x);
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    n=read(),m=read();
    ulp(i,1,n*m)a[i]=read();
    s=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    ulp(i,1,n*m){
    	if(a[i]==s){
    		work(i);
    		return 0;
		}
	}
    return 0;
}
/*
   _/_/_/_/     _/_/_/_/          _/              _/
   _/     _/    _/     _/         _/              _/    
   _/      _/   _/      _/        _/              _/ 
   _/     _/    _/     _/         _/              _/   
   _/_/_/_/     _/_/_/_/    _/_/_/_/_/_/_/  _/_/_/_/_/_/_/
   _/ _/        _/                _/              _/    
   _/   _/      _/                _/              _/
   _/     _/    _/                _/              _/ 
   _/       _/  _/                _/              _/
*/
