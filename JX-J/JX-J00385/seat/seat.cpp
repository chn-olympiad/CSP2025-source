#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[105],p;
    cin>>p;
    a[1]=p;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    //cout<<p<<endl;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==p){
            p=i;
            break;
        }
    }
    //cout<<p<<endl;
    if(p%n==0){
        cout<<p/n<<" ";
        if((p/n)%2==1)cout<<n;
        else cout<<1;
        return 0;
    }
    cout<<p/n+1<<" ";
    if((p/n+1)%2==1)cout<<p%n;
    else cout<<n+1-p%n;
    return 0;
}
//
