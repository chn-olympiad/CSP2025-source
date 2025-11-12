#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[5100];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++){
        for (int j=i+2;j<n;j++){
            for (int z=1;z<=n-1;z++){
                if (a[i]+a[i+1]+a[j]>max(a[i],a[i+1],a[j])) {ans++;}
            }
        }

    }
    return 0;
}
