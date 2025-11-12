#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int add=1,fst;
    for(int i=1;i<=n*m;i++){
        int x;
        cin>>x;
        if(i==1){
            fst=x;
        }else{
            if(x>fst){
                add++;
            }
        }
    }
    int y=(add+n-1)/n,x=add-(y-1)*n;
    if(y%2==1){
        cout<<y<<" "<<x;
    }else{
        cout<<y<<" "<<n-x+1;
    }
    return 0;
}
