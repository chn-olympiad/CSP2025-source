#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,ad,cnt=1;
    cin>>n>>m;
    cin>>ad;
    for(int i=2;i<=n*m;i++){
        int tmp;
        cin>>tmp;
        if(tmp>ad) cnt++;
    }
    int a=cnt/n+1,b=cnt%n;
    cout<<a<<" ";
    if(a%2==1){
        cout<<b;
    }
    else{
        cout<<n-b;
    }
    return 0;
}
