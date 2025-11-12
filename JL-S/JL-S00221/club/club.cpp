#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,shizhi,zuizhi=0;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int a[n],b[n],c[n];
        for(int j=0;j<n;j++){
            cin>>a[i]>>b[i]>>c[i];
        }
        for(int j=0;j<n;j++){
            if(shizhi=>zuizhi){
                zuizhi=shizhi;
            }
            for(o=n/2-j;o>=0;o--){
                for(int t=n-n/2-j;t>=0;t--){
                    for(int s=n-o-t;s>=0;s--){
                        zuizhi+=a[o]+b[t]+c[s];
                        shizhi=zuizhi;
                    }
                }
            }
        }
    }
    return 0;
}
