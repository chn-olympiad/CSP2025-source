#include<bits/stdc++.h>
using namespace std;
const int N=155;
#define ll long long
#define pb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
ll a[N],n,m,x,lstx,lsty=1,f=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    x=a[1];
    sort(a+1,a+1+(n*m));
    for(int i=n*m;i>0;i--){
        lstx+=f;
        if(lstx>n){
            lstx=n;
            f*=-1;
            lsty++;
        }
        if(lstx<1){
            lstx=1;
            f*=-1;
            lsty++;
        }
        if(a[i]==x){
            cout<<lsty<<' '<<lstx<<'\n';
            return 0;
        }
    }
    return 0;
}