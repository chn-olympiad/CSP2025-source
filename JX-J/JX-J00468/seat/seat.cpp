#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],r,x;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    r=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(r==a[n*m-i+1]){
            x=i;
            break;
        }
    }
    int i=1,l=1,j;//i count
    while(i<=x){
        for(j=1;j<=n;j++){
            if(i<x) i++;
            else{
                cout<<l<<" "<<j;
                return 0;
            }
        }
        l++;
        for(j=n;j>=1;j--){
            if(i<x) i++;
            else{
                cout<<l<<" "<<j;
                return 0;
            }
        }
        l++;
    }
    return 0;
}
