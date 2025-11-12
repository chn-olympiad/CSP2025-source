#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int read(){
    int x=0;
    char ch=getchar_unlocked();
    while(ch<'0'||ch>'9'){
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar_unlocked();
    }
    return x;
}
int main(){
    int cnt=0;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    n=read();
    m=read();
    x=read();
    for(int i=2;i<=n*m;i++){
        int y;
        y=read();
        if(y>x)cnt++;
    }
    int h=cnt/m+1;
    int l;
    if(h%2==1){
        l=cnt%m+1;
    }
    else{
        l=m-(cnt%m);
    }
    cout<<h<<" "<<l;
    return 0;
}
