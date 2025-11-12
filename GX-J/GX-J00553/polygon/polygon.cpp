#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int n;
    cin>>n;
    int a[5000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int q=0;
    for(int i=3;i<=n;i++){
        for(int j=0;j<n;j++){
            for(int k=1;k<n-j;k++){
                for(int z=2;z<n-k;z++){
                    if(j!=k&&j!=z&&k!=z){
                        if(a[j]+a[k]>a[z]&&a[j]+a[z]>a[k]&&a[k]+a[z]>a[j]){
                            q++;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
