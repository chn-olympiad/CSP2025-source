#include <bits/stdc++.h>
using namespace std;
int n,a[100],s,z;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int x=1;x<=n;x++){
                if(a[x]+a[j]+a[i]==s/3){
                    z++;
                }
            }
        }
    }
    cout<<z;
    return 0;
}
