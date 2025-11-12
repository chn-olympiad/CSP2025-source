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
int cnt[10];
string s;
int all=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(char c : s){
    	if(isdigit(c))cnt[c-'0']++,all++;
	}
	if(all==cnt[0])return putchar('0'),0;
	dlp(i,9,0){
		while(cnt[i]--)putchar('0'+i);
	}
    return 0;
}
//E:\FJ-J02180\number\number.out
//
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
