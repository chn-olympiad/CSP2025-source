#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500;
ll n,m,t,arr[maxn],s=1,x=1,y=1;
bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        ll x;
        cin>>x;
        if(i==1) t=x;
        arr[i]=x;
    }
    sort(arr+1,arr+1+n*m,cmp);
    while(s<=n*m){
        if(arr[s]==t){
            cout<<x<<' '<<y;
            break;
        }
        s++;
        if(x%2==1){
            if(y==n) x++;
            else y++;
        }
        else{
            if(y==1) x++;
            else y--;
        }
    }
    return 0;
}
