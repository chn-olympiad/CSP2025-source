#include <bits/stdc++.h>
using namespace std;
int a[105],n,m,b[15][15];
bool f(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int k=a[1],p=0;
    sort(a+1,a+n*m,f);
    for(int i=1;i<=n*m;i++){
        if(a[i]==k){
            p=i;
        }
    }
    if(p%n==0){
        cout<<p/n<<" ";
        if((p/n)%2==0){
            cout<<1;
            return 0;
        }
        else cout<<n;
    }
    else{
        cout<<p/n+1<<" ";
        int l=p/n+1;
        if(l%2==1){
            cout<<p%n;
            return 0;
        }
        else cout<<n-(p%n)+1;
    }
    return 0;
}
