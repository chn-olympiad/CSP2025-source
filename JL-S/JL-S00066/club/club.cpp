#include <bits/stdc++.h>
using namespace std;
int n;
int a[10005][5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int maxn=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }

            maxn+=max(max(a[i][1],a[i][2]),a[i][3]);
        }
        cout<<maxn;
    }
    return 0;
}
