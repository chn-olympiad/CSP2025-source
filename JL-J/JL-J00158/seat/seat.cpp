#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int n,m,a[N],score,idx;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    score=a[1];
    sort(a+1,a+(n*m)+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==score){
            idx=i;
        }
    }
    if(idx%n!=0){
        if((idx/n+1)%2==0){
            cout<<idx/n+1<<' '<<m-(idx%n)+1;
        }
        else{
            cout<<idx/n+1<<' '<<idx%n;
        }
    }
    else{
        if((idx/n)%2==0){
            cout<<idx/n<<' '<<1;
        }
        else{
            cout<<idx/n<<' '<<n;
        }
    }
    return 0;
}
