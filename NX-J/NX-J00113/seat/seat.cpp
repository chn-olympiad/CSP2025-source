#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,e,c2,r;
    float c;
    cin>>n>>m;
    int a[m*n],b[5];
    for(int i=0;i<n*m;i++){
         cin>>a[i];
         b[0]=a[0];
    }
    for(int i=0;i<n*m;i++){
        sort(a[i],a[i+1]);
        if(a[i]=b[0]){
            e=i;
        }
    }
    c2=e/n;
    c=e/n;
    if(c2=c){
        cout<<c;
    }else cout<<c2+1;
    cout<<(e+1)%m;
    return 0;
}
