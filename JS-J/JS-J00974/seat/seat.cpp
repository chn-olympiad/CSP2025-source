#include<bits/stdc++.h>
using namespace std;
const int N=124;
int a[N];
bool cmp(int x,int y){
    return x>y;
}
void solve(){
    int n,m,R;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    R=a[1];
    sort(a+1,a+n*m+1,cmp);
    int x=1,y=1;
    for(int i=1;i<=n*m;i++){
        if(a[i]==R){
            cout<<x<<" "<<y;
            return ;
        }
    //    cout<<x<<" "<<y<<"\n";
        if(x%2==1){
            if(y==n)x++;
            else{
                y++;
            }
        }else{
            if(y==1)x++;
            else{
                y--;
            }
        }
    //    if(x==m&&y==n)return ;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
     ____________       |
    |      |        _____|______
    |      |             |     |
    | _____|_____        |     |
    |      |            /      |
    /      |  \        /    \  /
   / ______|______    /      \/
                                 
*/