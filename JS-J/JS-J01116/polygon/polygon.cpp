#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,j=0;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int x=1;x<=n;x++){
        for(int y=x;y<=n;y++){
            for(int z=y;z<=n;z++){
                int k=2*max(a[x],a[y],a[z]),l=a[x]+a[y]+a[z];
                if(l>k){
                    j++;
                }
            }
        }
    }
    cout<<j;
    return 0;
}
