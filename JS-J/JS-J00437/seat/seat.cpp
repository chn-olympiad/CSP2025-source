#include<bits/stdc++.h>
using namespace std;
int n,m,a[102];
int k=1;
int main(){
    freopen(seat.in,"r",stdin);
    freopen(seat.out,"w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1])k++;
    }
    int s=1;
    for(int i=1;i<=m;i++){
        if(i%2==1)
            for(int j=1;j<=n;j++){
                if(s==k)cout<<i<<" "<<j;
                s++;
            }
        else for(int j=n;j>=1;j--){
                if(s==k)cout<<i<<" "<<j;
                s++;
            }
    }

    return 0;
}
