#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("seat.in","w",stdin);
    freopen("seat.out","r",stdout);
    int n,m;
    cin>>n>>m;
    int a[m*n],b,j,h,l;
    for(int i=0;i<m*n;i++){
        cin>>a[i];
    }
    b=a[0];
    sort(a,a+m*n);
    for(int i=0;i<m*n;i++){
        if(a[i]==b){
           j=m*n-i;
           break;
        }
    }
    if(j%n){
        l=j/n+1;
    }
    else l=j/n;
    if(l%2){
        h=j%n;
    }
    else h=n-j%n+1;
    if(h==0){
        h=n;
    }
    cout<<l<<' '<<h;
    return 0;
}
