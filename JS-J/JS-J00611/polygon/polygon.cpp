#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;
    char c;
    c=getchar();
    while(c!='-'&&(c<'0'||c>'9')){
        c=getchar();
    }
    if(c=='-'){
        f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*f;
}
int n,a[10000],ans=0;
void d(int x,int y,int z,int m,int c){
    if(x==y){
        if(m*2<z){
            ans++;
            ans=ans%998244353;
        }
        else return;
    }
    for(int i=c;i<=n;i++){
        d(x+1,y,z+a[i],max(m,a[i]),i+1);
    }
}
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){
        d(0,i,0,0,1);
    }
    cout<<ans;
    return 0;
}
