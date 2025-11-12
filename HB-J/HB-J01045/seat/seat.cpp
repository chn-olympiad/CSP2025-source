#include <bits/stdc++.h>
using namespace std;
int n,m,r,a[120];
bool cmp(int A,int B){
    return A>B;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int x=n*m;
    cin>>r;
    a[1]=r;
    for(int i=2;i<=x;i++){
        cin>>a[i];
    }
    sort(&a[1],&a[x]+1,cmp);
    int nx=1,ny=1;
    for(int i=1;i<=x;i++){
        if(a[i]==r){
            cout<<ny<<' '<<nx;
            return 0;
        }
        if(ny%2){
            nx++;
            if(nx>n){
                ny++;
                nx=n;
            }
        }
        else{
            nx--;
            if(nx<1){
                ny++;
                nx=1;
            }
        }

    }
    return 0;
}
