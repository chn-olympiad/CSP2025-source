#include<bits/stdc++.h>
using namespace std;
long long n,m,a[101],b,c[101][101];
inline bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i){
        cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+n*m+1,cmp);
    long long x=1;
    bool e=true;
    for(long long i=1;i<=m;++i){
        if(e){
            for(long long j=1;j<=n;++j){
                c[i][j]=a[x];
                ++x;
                //cout<<i<<' '<<j<<' '<<a[x-1]<<' ';
            }
        }else{
            for(long long j=n;j>=1;--j){
                c[i][j]=a[x];
                ++x;
                //cout<<i<<' '<<j<<' '<<a[x-1]<<' ';
            }
        }
        e=!e;
    }
    for(long long i=1;i<=m;++i){
        for(long long j=1;j<=n;++j){
            //cout<<c[i][j]<<' ';
            if(c[i][j]==b){
                cout<<i<<' '<<j;
                return 0;
            }
        }
        //cout<<'\n';
    }
    return 0;
}
