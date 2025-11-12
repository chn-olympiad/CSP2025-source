#include<bits/stdc++.h>
using namespace std;
bool cmp(int o,int oo){
    return o>oo;
}
int n,m,p=1;
int a[10005],b[105][105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int k=a[1];
    sort (a+1,a+1+n*m,cmp);
    for (int i=1;i<=m;i++){
        if (i%2) {
            for (int j=1;j<=n;j++){
                b[i][j]=a[p++];
                if (b[i][j]==k){
                    cout<<i<<' '<<j<<endl;
                    return 0;
                }
            }
        }else {
            for (int j=n;j>=1;j--){
                b[i][j]=a[p++];
                if (b[i][j]==k){
                    cout<<i<<' '<<j<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
