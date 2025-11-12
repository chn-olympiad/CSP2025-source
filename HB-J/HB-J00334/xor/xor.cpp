#include<bits/stdc++.h>
using namespace std;
int cnt;
inline int read(){
    int T=1,x=0;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-') T=-1;
        c=getchar();
    }
    while(isdigit(c)){
        int l=c-48;
        x=x*10+l;
        c=getchar();
    }
    return x*T;
}
int n,k;
int a[500005],book[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=read();
    k=read();
    for(int i=1;i<=n;i++){a[i]=read();cnt+=a[i];}
    if(k==0&&cnt==n) cout<<n/2;
    else if(k==0){
        int ans=0;ans+=n-cnt;
        int ckt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                ckt++;
            }else{
                ans+=ckt/2;ckt=0;
            }
        }
        cout<<ans;
    }
    else if(k==1){
        cout<<cnt;
    }
    return 0;
}
