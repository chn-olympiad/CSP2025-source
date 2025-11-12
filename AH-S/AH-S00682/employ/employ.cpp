#include<bits/stdc++.h>
#define int long long
using namespace std;
int input(){
    char ch=getchar_unlocked();
    int x=0,w=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-48;
        ch=getchar_unlocked();
    }
    return x*w;
}
void output(int x){
    char w[1005];
    int idx=0;
    if(x<0){
        putchar('-');
        x=-x;
    }
    do{
        w[++idx]=x%10;
        x/=10;
    }while(x);
    for(int i=idx;i>=1;i--)putchar(w[i]+48);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	mt19937 r(time(NULL));
	output(r()%998244353);
}
