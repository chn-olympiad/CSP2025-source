#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+6;
int n,m;
int a[N];
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(a[i]==r) r=i;
    }
    if(r%n==0){
        int x=r/n;
        if(x%2==0){
            cout<<x<<" "<<1;
        }else cout<<x<<" "<<n;
    }else{
        int x=r/n+1,y=r%n;
        if((x%2)==0){
            cout<<x<<" "<<n-y+1;
        }else cout<<x<<" "<<y;
    }
    return 0;
}
