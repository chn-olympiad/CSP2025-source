#include<bits/stdc++.h>
using namespace std;
const int mx=1E1+10;
int a[mx*mx];
int n,m,c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
        cin>>a[i];
    int rf=a[0],p=0;
    sort(a,a+n*m);
    for(int i=0;i<n*m;i++){
        if(rf==a[i]){
            p=n*m-i-1;
            c=p/n+1;
            if(c%2==0)
                r=n-(p%n);
            else
                r=p%n+1;
            break;
        }
    }
    cout<<c<<' '<<r;
    return 0;
}
