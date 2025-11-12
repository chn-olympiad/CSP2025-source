#include<bits/sidc++.h>
using namespace std;
int n,m,a,b[10086];
int main(){
    cin>>n>>m;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    if(n*m==1) {
        cout<<1<<' '<<1;
        return 0;
    }
    for(int i=0;i<n*m;i++){
        cin>>b[i];
        if(i==0) a=b[i];
    }
    sort(b,b+n*m);
    for(int i=n*m-1;i>=0;i--){
        if(b[i]==a)
            cout<<2*i<<' '<<2*i-1;
    }
}
