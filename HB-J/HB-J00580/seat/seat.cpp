#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[105],cnt;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n*m;i++){
        if(a[i]>a[1]) cnt++;
    }
    cnt+=1;
    int b=cnt/m;
    int c=cnt-b*m;
    if(c==0){
        if(b%2==0){
            cout<<b<<" "<<1;
        }else{
            cout<<b<<" "<<m;
        }
    }
    else{
        b+=1;
        if(b%2==0){
            cout<<b<<" "<<m-c+1;
        }
        else{
            cout<<b<<" "<<c;
        }
    }
    return 0;
}
