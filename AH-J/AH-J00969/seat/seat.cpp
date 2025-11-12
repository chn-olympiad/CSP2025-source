#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=11;
LL n,m,a[N*N],s[N][N],x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1) x=a[1];
    }
    sort(a+1,a+n*m+1);
    reverse(a+1,a+n*m+1);
    LL p=1,q=1;
    for(int i=1;i<=n*m;i++){
        s[q][p]=a[i];
        if(p%2==1){
            q++;
            if(q>n) p++,q=n;
        }else{
            q--;
            if(q<1) p++,q=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]==x) cout<<j<<" "<<i;
        }
    }
    return 0;
}
