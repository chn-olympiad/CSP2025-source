#include<bits/stdc++.h>
using namespace std;
long long t,u,y,r,a[1000],n=1,b[500][500];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>u;
    cin>>y;
    t=u*y;
    for(int i=1;i<=t;i++)
        cin>>a[i];
    r=a[1];
    for(int i=t;i>=1;i--){
        for(int j=1;j<=i;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
        long long  j=1;
    for(int i=1;i<=u;i++){
            b[i][j]=a[n];
            if(b[i][j]==r){
            cout<<j<<" "<<i;
          break;
           }
            n++;
            if(i==u){
                i=0;
                j++;
            }
        }
    return 0;
}
