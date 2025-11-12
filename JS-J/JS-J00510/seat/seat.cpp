#include<bits/stdc++.h>
#define int long long
using namespace std;
struct ct{
    int x,num;
}a[200];
bool cmp(ct c1,ct c2){
    return c1.x>c2.x;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m;
    for(int i=1;i<=n*m;++i){
        cin>>a[i].x;
        a[i].num=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;++i){
        if(a[i].num==1) {
            k=i;
            break;
        }
    }
    int ansx=ceil(k*1.0/n),ansy;
    if(ansx%2){
        ansy=k%n;
        if(!ansy) ansy=n;
    }else{
        ansy=n-k%n+1;
        if(ansy==n+1) ansy=1;
    }
    cout<<ansx<<" "<<ansy<<endl;
    return 0;
}

/*
3 3
94 95 96 97 98 99 100 93 92
*/

