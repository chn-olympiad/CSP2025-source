#include<bits/stdc++.h>
using namespace std;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    set<int,greater<int> > st;
    int n,m,k=0; cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        int l; cin>>l;
        if(i==1){
            k=l;
        }
        st.insert(l);
    }
    int x=0,y=1;
    for(int u : st){
        x++;
        if(x==n+1){
            x=1;
            y++;
        }
        if(u==k){
            break;
        }
    }
    if(y%2==1){
        cout<<y<<" "<<x<<'\n';
    }else{
        if(x==1){
            x=0;
        }
        cout<<y<<" "<<n-x<<'\n';
    }
    return 0;
}
