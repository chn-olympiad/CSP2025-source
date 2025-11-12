#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,ansn,ansm,wei;
    cin>>n>>m;
    int cj[110];
    for(int i=1;i<=n*m;i++)cin>>cj[i];
    int tag=cj[1];
    for(int i=1;i<=n*m;i++){
        for(int j=i+1;j<=n*m;j++){
            if(cj[i]<cj[j])swap(cj[i],cj[j]);
        }
    }
    for(int i=1;i<=n*m;i++){
        if(cj[i]==tag){
            wei=i;
            break;
        }
    }
    ansm=(wei-1)/n+1;
    while(wei>n)wei-=n;
    if(ansm%2==1)ansn=wei;
    else ansn=n-wei+1;
    cout<<ansm<<' '<<ansn;
    return 0;
}
