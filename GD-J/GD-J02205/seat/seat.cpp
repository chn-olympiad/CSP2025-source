#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],g,c=1,r=1;
bool comp(const long long&a,const long long&b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n*m;++i)cin>>a[i];
    g=a[1];
    sort(a+1,a+n*m+1,comp);
    for(long long i=1,lst=0;i<=n*m;++i){
        c=(i-1)/n+1;
        if(c==lst){
            if(c%2)++r;
            else --r;
        }else lst=c;
        if(a[i]==g){
            cout<<c<<' '<<r;
            break;
        }
    }
    return 0;
}
