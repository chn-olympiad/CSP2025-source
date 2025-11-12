#include<bits/stdc++.h>
using namespace std;
int xo(int a,int b){
    if(a==1){
        if(b==1){
            return 0;
        }else{
            return 1;
        }
    }else{
        if(b==1){
            return 1;
        }else{
            return 0;
        }
    }
}
int nxo(int a,int b){
    int c=0,d=1;
    while(a!=0||b!=0){
        int e,f;
        e=a%2;
        f=b%2;
        c+=xo(e,f)*d;
        d*=2;
        a/=2;
        b/=2;
    }
    return c;
}
int ans=0,a[500001],v[500001],v2[500001];
int n,k;
int f(int i){
    if(v[i]!=-1)return v[i];
    int rt=0;
    for(int j=i;j<=n;j++){
        if(v2[j]!=-1){
            rt=max(rt,v2[j]);
            continue;
        }
        int trt=0;
        int g=a[j];
        if(g==k){
            rt=max(rt,1+f(j+1));
            trt=max(trt,1+f(j+1));
        }
        for(int l=j+1;l<=n;l++){
            g=nxo(g,a[l]);
            if(g==k){
                rt=max(rt,1+f(l+1));
                trt=max(trt,1+f(l+1));
            }
        }
        v2[j]=trt;
    }
    v[i]=rt;
    return rt;
}
int main(){
    memset(v,-1,sizeof(v));
    memset(v2,-1,sizeof(v2));
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<f(1);
}
