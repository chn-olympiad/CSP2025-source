#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,f=0,c=1,r=1;
    cin>>n>>m;
    int e=n*m;
    for(int i=1;i<=e;i++){
        cin>>a[i];
        f=a[1];
        if(f<a[i]){
            r++;

        }
        if(r>m){
            c++;
            r-=m;
        }
    }
    cout<<c<<" "<<r;

    return 0;
}
