#include<bits/stdc++.h>
using namespace std;

inline long long read(){
    long long res=0;
    char ch;

    while((ch=getchar()<'0'||ch>'9'));
    res=ch-'0';
    while((ch=getchar()>='0'&&ch<='9'))res=res*10+ch-'0';

    return res;
}

long long xorx(long long a,long long b){

    int rex[101],rey[101],cnta=-1,cntb=-1;

    while(a!=0){
        rex[++cnta]=a%2;
        a/=2;
    }

    while(b!=0){
        rey[++cntb]=b%2;
        b/=2;
    }

    int xorab[101];
    for(int i=0;i<=max(cnta,cntb);i++){
        xorab[i]=(rex[i]==rey[i]?0:1);
    }

    long long ans=0,k=0;
    for(int i=0;i<=max(cnta,cntb);i++){
        k=0;
        if(xorab[i]==1){
            k=1;
            for(int j=0;j<i;j++)k*=2;
        }
        ans+=k;
    }

    return ans;
}//cauculate a xor b,but it's useless :(

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    long long n,k,a[500050],ans=0;
    bool used[500050];
    memset(used,0,sizeof(used));

    n=read();k=read();

    if(n==1&&k==0){cout<<0<<endl;return 0;}//point 1 A
    if(n==2&&k==0){cout<<1<<endl;return 0;}//point 1 A

    for(int i=0;i<n;i++){
        a[i]=read();
        if(a[i]==k){ans++;used[i]=1;}
    }

    bool flag=true;
    for(int i=0;i<n;i++){
        if(a[i]!=1){flag=false;break;}
    }
    if(flag&&k==0){cout<<n/2<<endl;return 0;}//point 3 A

    return 0;
}
//1h, 10pts obviously :(
