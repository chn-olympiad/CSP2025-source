#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r,c,d;
    cin>>m>>n>>d;
    for(int i=1;i<=d;i++){
        if(a[i]<a[i+1]){
            r++;
        }
        if(r+1>n){
            c++;
        }
    }
    cout<<c<<r;
    return 0;
}
