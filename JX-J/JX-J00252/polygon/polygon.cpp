#include<bits/stdc++.h>
using namespace std;
long long a[5001]={};
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,s=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int o=3;o<=n;o++){
        for(int i=1;i<=o;i++){
            for(int j=i+1;j<=o;j++){
                if(o!=i and o!=j){
                    if(a[i]+a[j]>a[o] and a[i]+a[o]>a[j] and a[o]+a[j]>a[i]){
                        s++;
                    }
                }

            }
        }
    }
    cout<<s%998244353;
    return 0;
}
