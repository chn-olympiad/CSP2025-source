#include<bits/stdc++.h>
using namespace std;
int a1 = 0;
int arr(0);
int n(0),m(0);
int cnt(0);
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a1;
    for(int i=0;i<n*m-1;++i){
        cin>>arr;
        if(arr>a1)
            cnt++;
    }
    int c = cnt/n+1;
    int r = 0;
    if(c%2==0){
        r = n-cnt%n;
    }else{
        r = cnt%n+1;
    }
    cout<<c<<' '<<r;
    return 0;
}
