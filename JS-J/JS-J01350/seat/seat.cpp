#include<bits/stdc++.h>
using namespace std;
int a[1005];
int seat[105][105];
int n,m,k;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    k=a[1];
    int sss=n*m;
    sort(a+1,a+sss+1);

    bool f=1;
    for(int i=1;i<=n;i++){
        if(f==1){
            for(int j=1;j<=m;j++){
                seat[i][j]=a[sss];
                // cout<<a[sss]<<" "<<i<<" "<<j<<endl;;
                if(a[sss]==k){
                    cout<<i<<" "<<j;
                    return 0;
                }
                sss--;
            }
            f=0;
        }
        else{
            for(int j=m;j>=1;j--){
                seat[i][j]=a[sss];
               // cout<<a[sss]<<" "<<i<<" "<<j<<endl;;
                if(a[sss]==k){
                    cout<<i<<" "<<j;
                    return 0;
                }
                sss--;
            }
            f=1;
        }
    }
    return 0;
}
