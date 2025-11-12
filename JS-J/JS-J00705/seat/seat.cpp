#include<bits/stdc++.h>
// #define ll long long
// #define inf INT_MAX
using namespace std;
const int N=1e6+7;
const int M=1e6+7;
const int mod=1e9+7;
int a[N];int cnt;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin >>n>>m;
    for(int i=1;i<=n*m;i++)cin >>a[i];
    int t=a[1];
    sort(a+1,a+1+n*m,greater<int>());
    int x=1,y=1;bool f=1;
    for(int i=1;i<=n*m;i++){
        // cout<<x<<" "<<y<<endl;
        // cout<<x<<" "<<y<<" "<<a[i]<<" "<<t<<endl;
        if(a[i]==t){
            cout<<x<<" "<<y<<endl;
            return 0;
        }
        if(f){
            y++;
            if(y>m){
                x++;
                y=m;
                f=0;
            }
        }else{
            y--;
            if(y<=0){
                x++;
                y=1;
                f=1;
            }
        }
    }
    return 0;
}