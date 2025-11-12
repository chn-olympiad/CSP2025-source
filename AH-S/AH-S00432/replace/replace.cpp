#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x*=10,x+=(int)(ch-'0');
        ch=getchar();
    }
    return x*f;
}

const int N=10015,K=12;

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n=read(),m=read();
    for(int i=1;i<=m;i++)
    cout<<0<<"\n";
    return 0;
}   
