#include<bits/stdc++.h>
using namespace std;
int n,m,lmj[10000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>lmj[i];
    }
    int love=lmj[1];

    sort(lmj+1,lmj+1+n*m);
    for(int i=1;i<=n*m;i++){
        if(lmj[i]==love){
            love=n*m-i+1;
            break;
        }
    }
    int yzy=floor(love/n)+1;
    if(love<=n){
        yzy=1;
    }
    if(yzy%2==1){
        cout<<yzy<<" "<<love-(yzy-1)*n;
    }
    else{
        cout<<yzy<<" "<<yzy*n-love+1;
    }
    return 0;
}
