#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,b[101],c;
    int a[101][101];
    for(int i=1;i<=100;i++[
        b[i]=0;
    ]
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                b[i]=max(b,a[i][j]);
            }
            c+=b[i];
        }
        cout<<c;
    }

    return 0;
}