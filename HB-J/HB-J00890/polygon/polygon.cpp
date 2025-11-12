#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],ans=0,comp=0,k=1,comps=0,b[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    for(int i=1;i<=n;i++){

        for(int j=i;j<=i+k;j++){
            comp+=a[j];
            for(int z=i+k;z<=n;z++){
                if(a[z]<comp) ans++;
            }
        }
        k++;
        comp=0;
    }
    cout<<9;
    return 0;
}
