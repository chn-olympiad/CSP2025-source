#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int b=n*m;
    int c[110];
    for(int i=1;i<=b;i++){
        cin>>c[i];
    }
    int cj=c[1];
    for(int i=1;i<=b;i++){
        if(c[i]<c[i+1]){
            swap(c[i],c[i+1]);
        }
    }
    for(int i=1;i<=b;i++){
        if(c[i]==cj)cout<<1<<" "<<i;
    }

    return 0;
}
