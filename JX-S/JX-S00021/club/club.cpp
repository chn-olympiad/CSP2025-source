#include<bits/stdc++.h>
using namespace std;
int t,n,a[10005][4],s,a1=0,a2=0,a3=0,A1,A2,q;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t!=0){
        cin>>n;
        s=n/2;
        for(int j=1;j<=n;j++){
            cin>>a[j][1]>>a[j][2]>>a[j][3];
        }
        cout<<a[1][1]*n;
    }
    return 0;
}
