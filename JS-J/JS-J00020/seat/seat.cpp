#include<bits/stdc++.h>
using namespace std;
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int x,y;
    cin>>x;
    y=x;
    set<int,greater<int>>a;
    a.insert(x);
    for(int i=2;i<=n*m;i++){
        cin>>x;
        a.insert(x);
    }
    int k=1;
    for(int i:a){
        if(i==y){
            break;
        }
        k++;
    }
    x=(k+n-1)/n;
    if(x%2==1){
        cout<<x<<' '<<(k-1)%n+1;
    }else{
        cout<<x<<' '<<n-(k-1)%n;
    }
    return 0;
}
