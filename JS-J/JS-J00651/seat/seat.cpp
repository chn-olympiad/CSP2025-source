#include<bits/stdc++.h>
using namespace std;
int test[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int q;
    for(int i=1;i<=n*m;i++){
        cin>>test[i];
    }
    q=test[1];
    sort(test+1,test+n*m+1,greater<int>());
    int ansn,ansm,index;
    for(int i=1;i<=n*m;i++){
        if(test[i]==q){
            index=i;
            break;
        }
    }
    if(index%n==0){
        ansm=index/n;
    }else{
        ansm=index/n+1;
    }
    if(ansm%2!=0){
        ansn=index%n;
    }else{
        ansn=n-index%n+1;
    }
    cout<<ansm<<" "<<ansn;

    return 0;
}
