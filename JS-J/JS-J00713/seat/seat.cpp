#include<bits/stdc++.h>
using namespace std;

int m,n,i,j,a[1000],tmp,c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;//nline
    for(i=1;i<=n*m;i++){
        cin>>a[i];
    }
    tmp=a[1];
    sort(a+1,a+n*m+1);
    for(i=1;i<=n*m;i++){
        if(a[n*m+1-i]==tmp){
            c=(i-1)/n+1;
            r=(i-1)%n+1;
            r=(c%2)?r:(n+1-r);
            cout<<c<<" "<<r;
            return 0;
        }
    }
    return 0;
}
