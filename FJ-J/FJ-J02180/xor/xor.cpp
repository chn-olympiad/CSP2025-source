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
#define N 500005
int n,k;
int a[N];
unordered_map<int,int> Map;
int now=0;
int hanser=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=read(),k=read();
    ulp(i,1,n){
    	a[i]=read();
    	now^=a[i];
    	//k^now^now=k
    	//x^need=k need=k^now
    	if(Map.count(k^now)||now==k){
    		//del head||all 
    		++hanser;
    		Map=unordered_map<int,int>();
    		now=0;
		}
    	else Map[now]++;
	}
	write(hanser);
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
