#include<bits/stdc++.h>
using namespace std;
int x[110];
int n,m,h,t;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>x[i];
    }
    h=x[1];
    sort(x+1,x+n*m+1);
    if(h==x[n*m]){
        cout<<1<<' '<<1;
        return 0;
    }
    if(h==x[1]){
        if(m%2==0){
           cout<<n<<' '<<1;
        }
        else cout<<n<<' '<<m;
        return 0;
    }
    cout<<n-1<<m-1;
    return 0;
}
