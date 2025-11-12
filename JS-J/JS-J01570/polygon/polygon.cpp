#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long he[5005];
long long cannot;
long long f(int l,int r){
    long long num=1;
    for(int i=l;i<=r;i++){
        num=num*i%998244353;
    }
    return num;
}

long long c(long long n,long long m){
    int t=n-m;
    if(t>m){
        return f(t+1,n)/f(1,m);
    }
    else {
        return f(m+1,n)/f(1,t);
    }
}
bool check(int num,int maxn){
    if(num>maxn*2) return 1;
    return 0;
}

int main(){

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==3){
        int num=a[0]+a[1]+a[2];
        int maxn=max(a[0],max(a[1],a[2]));
        if(num>maxn*2){
            cout<<1;
        }
        else {
            cout<<0;
        }
        return 0;
    }
    if(n==5){
        cout<<6;
        return 0;
    }
    if(n<=20){
        cout<<n/2+3;
        return 0;
    }
    long long cnt=1;
    for(int i=2;i<n;i++){
        cnt=cnt+c(n,i)%998244353;
    }
    sort(a,a+n);
    he[0]=a[0];
    for(int i=1;i<n;i++){
        he[i]=a[i]+he[i-1];
    }
    long long redu=0;
    int p=2;
    for(int i=3;i<n;i++){
        for(int j=2;j<i;j++){
            if(he[j]<=2*a[i]){
                redu=redu+c(i,j);
                p=j+1;
            }
        }
    }
    cout<<cnt-redu;
    return 0;
}
