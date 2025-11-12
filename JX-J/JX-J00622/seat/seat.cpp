#include<bits/stdc++.h>
using namespace std;
int r,c,b[105],n,m,x;
int main(){
    freopen("","r",stdin);
    freopen("","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    b[1]=x;s
    sort(b+1,b+n*m+1);
    for(int i=m*n;i>=1;i--){
        if(b[i]==x){
            cout<<1<<' '<<i;
        }
    }
    return 0;
}
