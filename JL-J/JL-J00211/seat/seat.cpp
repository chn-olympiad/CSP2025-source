#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[110],n,m,x,b[11][11],i,z;
    cin>>n>>m;
    for(i=1;i<=n*m;i++)
        cin>>a[i];
    x=a[1];
    z=n*m;
    sort(a+1,a+i);
    for(i=1;i<=n;i++){
        if(i%2!=0){
            for(int j=1;j<=m;j++){
                if(a[z]==x){
                    cout<<i<<" "<<j;
                    return 0;
                }
                z--;
            }
        }
        else{
            for(int j=m;j>=1;j--){
                if(a[z]==x){
                    cout<<i<<" "<<j;
                    return 0;
                }
                z--;
            }
        }
    }
    return 0;
}
