#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>m>>n;
    int a[m*n];
    for(int i=0;i<m*n;i++){
        cin>>a[i];
    }
    int ans=1;
    for(int i=1;i<m*n;i++){
        if(a[i]>a[0]){
            ans++;
        }
    }

    int x,y;

    if(ans%m!=0) x=ans/m+1;
    else x=ans/m;
    if(x%2==0){
        y=n-ans%m+1;
    }
    else y=ans-m*(x-1);
    cout<<x<<' '<<y;
    return 0;
}
