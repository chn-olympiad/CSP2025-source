#include<bits/stdc++.h>
using namespace std;
const int N=100000000;
int a[N+1],n,m,ord,mark,tot;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    tot=n*m;
    for(int i=0;i<tot;i++) cin>>a[i];
    mark=a[0];
    for(int j=0;j<tot-1;j++){
        for(int k=0;k<tot-1;k++){
            if(a[k]<a[k+1]){
                swap(a[k+1],a[k]);
            }
        }
    }
    for(int i=0;i<tot;i++){
        if(a[i]==mark) ord=i;
    }
    int c=(ord)/n,r=ord%n;
    if(c%2==1){
        r=n-r-1;
    }
    r+=1;
    c+=1;
    cout<<c<<' '<<r;
    return 0;
}
