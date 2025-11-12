#include<bits/stdc++.h>
using namespace std;
long long a[5050];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j++){
            long long he=0,mx=0;
            for(int k=i;k<=j;k++){
                he+=a[k];
                mx=max(mx,a[k]);
            }
            if(he>mx*2){
               js++;
               js%=998244353;
               for(int k=i;k<=j;k++){
                cout<<k<<" ";
               }
               cout<<endl;
            }
        }
    }
    cout<<js;
    return 0;
}
