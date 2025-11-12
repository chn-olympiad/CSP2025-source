#include <bits/stdc++.h>
using namespace std;
int m,n,a[109],h=1,l=0,r,t=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1],t=m*n+1;
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n;i++){
        l++;
        for(int j=1;j<=m;j++){
            t--;
            if(j!=1){
                if(i%2==1){
                    h++;
                }
                else{
                    h--;
                }
            }
            if(a[t]==r){
                cout<<l<<' '<<h<<endl;
                return 0;
            }

        }
    }
    cout<<endl;
    return 0;
}
