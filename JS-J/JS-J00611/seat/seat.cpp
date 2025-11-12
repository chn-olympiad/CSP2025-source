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
int main(){
    int n,m,a,b[1000],cnt;
    n=read();
    m=read();
    for(int i=1;i<=n*m;i++){
        b[i]=read();
    }
    a=b[1];
    sort(b+1,b+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(b[i]==a){
            cnt=n*m-i+1;
        }
    }
    cout<<(cnt-1)/n+1<<' ';
    if(((cnt-1)/n+1)%2==1){
        cout<<(cnt-1)%n+1;
    }
    else{
        cout<<n-((cnt-1)%n+1)+1;
    }
    return 0;
}
