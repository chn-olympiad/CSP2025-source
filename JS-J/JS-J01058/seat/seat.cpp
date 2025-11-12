#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=1;i<n*m;i++){
        if(a[i]>a[0]){
             cnt++;
        }
    }
    int l=cnt/m,hng;

    if(l%2==0){
        hng=cnt-(l*m)+1;
    }else{
        hng=m-(cnt-(l*m));
    }
    l++;
    cout<<l<<" "<<hng;
    return 0;
}
