#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int r=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
        if(a[i]==r){
            r=i;
            break;
        }
    int l=(r-1)/n+1;
    if(l%2==1) cout<<l<<' '<<r-(l-1)*n;
    else cout<<l<<' '<<l*n-r+1;
    return 0;
 }
