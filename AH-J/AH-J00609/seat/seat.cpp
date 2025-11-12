
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdout);
    freopen("seat.out","w",stdout);
    int n,m,c,r;
    int q=0;
    cin>>n>>m;
    int k=n*m;
    char a[k];
    for(int i=0;i<=k;i++){
        cin>>a[i];
        if(a[1]<a[i]){
            q++;
        }
    }
    if(q%n==0){
        c=q/n;
        if(q/n%2==0){
            r=1;
        }else{
            r=n;
        }
    }else{
        c=q/n+1;
        if(q/n%2==0){
            r=n+1-q%n;
        }else{
            r=q%n;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
