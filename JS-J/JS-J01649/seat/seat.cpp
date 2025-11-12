#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    int n,m;
    cin>>n>>m;
    int r,tot=0,k;
    cin>>r;
    for(int i=1;i<n*m;i++){
        cin>>k;
        if(k>r){
            tot++;
        }
    }
    int l=(tot/n)+1,j;
    int query=l%2,w=tot%n+1;
    freopen("seat.out","w",stdout);
    if(query==1){
        j=w;
    }
    else{
        j=n+1-w;
    }
    cout<<l<<' '<<j;

    return 0;
}
