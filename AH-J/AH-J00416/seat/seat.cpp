#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105];
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>a[(i-1)*n+j];
        }
    }
    int h;
    h = a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i = 1;i<=n*m;i++){
        if(a[i] == h){
            h = i;
            break;
        }
    }
    int x,y,op;
    x = 0;
    y = 1;
    op = 1;
    while(h--){
        x = x+op;
        if(x>n){
            x = n;
            y++;
            op = -1;
        }else if(x<1){
            x = 1;
            y++;
            op = 1;
        }
    }
    cout<<y<<" "<<x<<"\n";
    return 0;
}
