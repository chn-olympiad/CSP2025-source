#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector <int> a(n*m,0);
    int u = 0;
    for(int i = 0;i < n*m;i++){
        cin>>a[i];
        if(i == 0) u = a[i];
    }
    sort(a.begin(),a.end());
    int u_index = 0;
    for(int i = 0;i < n*m;i++){
        if(a[i] == u){
            u_index = i;
            break;
        }
    }
    u_index = n*m-1-u_index;
    cout<<u_index/n+1<<" ";
    if((u_index/n + 1) % 2){
        cout<<u_index%n+1;
    }
    else{
        cout<<n-u_index%n;
    }
    return 0;
}
