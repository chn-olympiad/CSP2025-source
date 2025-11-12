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
#define mod 998244353
#define ll long long

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
#define N 5005
ll n;
ll a[N];
ll dp[N*N];
ll pre[N];
ll hanser=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=read();
    ulp(i,1,n)a[i]=read(),pre[i]=pre[i-1]+a[i];
    sort(a+1,a+n+1);
    dp[0]=1;
    ulp(i,1,n){
    	//i=1 a[1]>a[1]->false not now
    	//i=2 a[2]+a[1]>a[2]*2->false because a[2]>a[1]
    	//don't worry m<3
    	ll now=0;
    	ulp(j,a[i]+1,pre[i-1]){
    		now+=dp[j];
			if(now>=mod)now-=mod;
		}
    	dlp(j,pre[i],a[i]){
    		dp[j]+=dp[j-a[i]];
    		if(dp[j]>=mod)dp[j]-=mod;
		}
		hanser+=now;
		if(hanser>=mod)hanser-=mod;
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
