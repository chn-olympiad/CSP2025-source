#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110],b,c,d;//c wei pai,d wei lie.
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    b=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==b){
            c=i%(2*n);
            if(c==0) c=1;
            if(c>n){
                c=2*n-c+1;
            }
            d=int(ceil(1.0*i/n));
            cout<<d<<" "<<c;
            return 0;
        }
    }
    return 0;
}
