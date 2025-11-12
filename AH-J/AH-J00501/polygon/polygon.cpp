#include<iostream>
#include<cstdio>
//define bits/stdc++.h
using namespace std;
int n,a[5005];
bool f;
long long ans;
void g(int x,int idx,int sum,int maxn){
    if(x==0){
        if(sum>2*maxn) ans++;
        return ;
    }
    for(int i=idx+1;i<=n;i++){
        g(x-1,i,sum+a[i],max(maxn,a[i]));
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=1) f=1;
    }
    if(n==3){
        int sum=0,maxn=0;
        for(int i=1;i<=n;i++){
            sum+=a[i];
            maxn=max(a[i],maxn);
        }
        if(sum>2*maxn)cout<<1;
        else cout<<0;
    }else if(n<=20){
        for(int i=3;i<=n;i++){
            g(i,0,0,0);
        }
        cout<<ans;
    }
    if(!f){
        long long x=2/(n*(n-1));
        for(int i=3;i<=n;i++){
            x=x*(long long)i/(long long)(n+1-i);
            ans+=x;
        }
        printf("%lld",ans);
    }
//    sort(a+1,a+1+n);
    return 0;
}
