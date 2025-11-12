#include<bits/stdc++.h>
using namespace std;
long long a,b,c,n,m,x[105],k;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>x[i];
        a=x[1];
    }
    sort(x+1,x+1+n*m);
    b=n*m;
    for(int i=1;i<=n;i++){
        if(i%2==1) k=1;
        else k=m;
        for(int j=1;j<=m;j++){
            if(x[b]==a){
                cout<<i<<" "<<k;
                return 0;
            }
            if(i%2==1) k++;
            else k--;
            b--;
        }
    }
    return 0;
}
