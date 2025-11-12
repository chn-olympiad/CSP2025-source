#include<bits/stdc++.h>
using namespace std;
int t,n,a1[3],b1[3],a[100001],b[100001],c[100001];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n=2){
            for(int j=1;j<=2;j++){
                cin>>a1[j];
            }
            for(int j=1;j<=2;j++){
                cin>>b1[j];
            }
            cout<<max(a1[1]+b1[2],a1[2]+b1[1])<<endl;
        }
        else{
            for(int j=1;j<=n;j++){
                cin>>a[j]>>b[j]>>c[j];
                sort(a+1,a+n+1);
                cout<<a[n]<<endl;
            }
        }
    }
    return 0;
}
