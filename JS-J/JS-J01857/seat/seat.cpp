#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[110],xr,r,c=1;
bool f;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    xr=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(f==0){
            r++;
        }
        else{
            r--;
        }
        if(r>n&&f==0){
            r=n;
            c++;
            f=1;
        }
        else if(r<1&&f==1){
            r=1;
            c++;
            f=0;
        }
        if(a[i]==xr){
            cout<<c<<" "<<r;
            return 0;
        }
    }
    return 0;
}
