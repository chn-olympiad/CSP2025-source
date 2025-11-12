#include<bits/stdc++.h>
using namespace std;
int a[200005][200005];
int main(){
    freopen("clud.in","r",stdin);
    freopen("clud.out","w",stdout);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i];
            }
            cin>>a[j];
        }
    }

    return 0;
}
