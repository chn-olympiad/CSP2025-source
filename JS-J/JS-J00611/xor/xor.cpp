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
int n,k;
long long a[500001],m=0,ma=0;
int main(){
    n=read();
    k=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=n;i++){;
        for(int j=1;j<=n-i+1;j+=i){
                long long cnt=a[j];
            for(int x=j+1;x<=j+i-1;x++){
                cnt=cnt^a[x];
            }
            if(cnt==k){
                m++;
            }
        }
        ma=max(ma,m);
        m=0;
    }
    cout<<ma;
    return 0;
}
