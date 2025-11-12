#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int seat[N],copy1[N],a1;
int nb[N][N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n*m;i++){
        cin>>seat[i];
        copy1[i]=seat[i];
    }
    sort(seat,seat+n*m);
    for(int i = 1;i<=n*m;i++){
        if(seat[i]==copy1[1]){
            a1=i;
        }
    }
    if(a1==1){
        cout<<n<<" "<<m;
    }else if(a1==n*m-1){
        cout<<1<<" "<<1;
    }else if(a1==n*m-2){
        cout<<1<<" "<<2;
    }else if(a1==2){
        cout<<n<<" "<<m-1;
    }
}
