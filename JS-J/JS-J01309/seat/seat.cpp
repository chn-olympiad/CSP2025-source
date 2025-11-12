#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int i;
    cin>>i;
    int l,cnt=1;
    for(int t=2;t<=n*m;t++){
        cin>>l;
        if(l>i){
            cnt++;
        }
    }
    int q=cnt/n;
    int p=(cnt-n*q);
    if(p==0){
        cout<<q<<" ";
        if(q%2==0){
            cout<<1;
        }
        else{
            cout<<n;
        }
    }
    else{
        cout<<q+1<<" ";
        if((q+1)%2==1){
            cout<<p;
        }
        else{
            cout<<n-p+1;
        }
    }
    cout<<endl;
    return 0;
}
