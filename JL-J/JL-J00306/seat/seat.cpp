#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10+7;
const int M=N*N;

ll mp[N][N],a[M],p;
ll n,m,t;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    t=n*m;
    for(int i=1;i<=t;i++)
        cin>>a[i];
    p=a[1];
    sort(a+1,a+t+1,greater<ll>());
    ll x=1,y=1;
    bool up=1;
    for(int i=1;i<=t;i++){
        mp[x][y]=a[i];
        //cout<<a[i]<<":"<<x<<','<<y<<endl;
        if(a[i]==p){
            cout<<x<<" "<<y<<endl;
            break;
        }
        //out
        if(up&&y==n){
            x++;
            up=0;
            continue;
        }
        if(!up&&y==1){
            x++;
            up=1;
            continue;
        }
        //in
        if(up) y++;
        else y--;
    }
    return 0;
}
