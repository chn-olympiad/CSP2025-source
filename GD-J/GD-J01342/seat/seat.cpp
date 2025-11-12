#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,ans;
int a[114];
int x,y;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }ans=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    x=1,y=1;
    int cnt=0;
    while(cnt<=n*m){
        while(y<=m&&cnt<=n*m){
            cnt++;
            if(a[cnt]==ans){
                cout<<x<<" "<<y;
                return 0;
            }y++;
        }y--,x++;
        while(y>=1&&cnt<=n*m){
            cnt++;
            if(a[cnt]==ans){
                cout<<x<<" "<<y;
                return 0;
            }y--;
        }y++,x++;
    }
    return 0;
}
