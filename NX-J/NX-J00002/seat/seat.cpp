#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int num[n*m];
    int a;
    for(int i=0;i<n*m;i++){
        cin>>num[i];
        a=num[0];
    }
    sort(num,num+n*m);
    int nn=n*m-1;
    for(int i=1;i<=m;i++){
        if(i%2){
            for(int j=1;j<=n;j++){
                if(num[nn]==a){
                    cout<<i<<' '<<j;
                    return 0;
                }
                nn--;
            }
        }
        else{
            for(int j=n;j>0;j--){
                if(num[nn]==a){
                    cout<<i<<' '<<j;
                    return 0;
                }
                nn--;
            }
        }
    }
    return 0;
}
