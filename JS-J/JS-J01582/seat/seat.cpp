#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a1,s;
    cin>>n>>m;
    int a[n*m+1];
    s=1;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1){
            a1=a[i];
        }
        else{
            if(a1<a[i]){
                s++;
            }
        }
    }
    int c=s/n+1;
    int r=s%n;
    if(r==0){
        c--;
        r=n;
    }
    if(c%2==0){
        r=n-r+1;
    }
    cout<<c<<' '<<r;
    return 0;
}
