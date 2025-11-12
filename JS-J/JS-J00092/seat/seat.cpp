#include<bits/stdc++.h>
#define itn int
#define fro for
#define elif else if
#define endl "\n"
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using namespace std;
ll n,m;
ll c,r,fd;
ll a[1000007];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    fd=a[1];
    sort(a+1,a+1+n*m,greater<ll>());
    c=1,r=1;
    for(int i=1;i<=n*m;i++){
        if(a[i]==fd)break;
        if(c%2==1){
            r++;
            if(r>n){
                r--;c++;
            }
        }else{
            r--;
            if(r<=0){
                r++;c++;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
