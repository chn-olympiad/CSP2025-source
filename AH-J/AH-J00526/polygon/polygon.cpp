#include<bits/stdc++.h>
using namespace std;
long long cnt,a[10000000];
long long n,zdd;
void dd(long long c,long long ge,long long zd,long long x,long long zh){
    if(ge==c){
        if(zd*2<zh){
            cnt++;
            cnt%=998244353;
        }
    }
    for(int i=x+1;i<=n;i++){
        zh+=a[i];
        zdd=zd;
        zd=max(zd,a[i]);
        ge++;
        dd(c,ge,zd,i,zh);
        ge--;
        zd=zdd;
        zh-=a[i];
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        dd(i,0,0,0,0);
    }
    cout<<cnt;
    return 0;
}

