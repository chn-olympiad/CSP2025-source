#include<bits/stdc++.h>
using namespace std;
int t,n,maxn;
int a[100005][3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i][0]>a[i-1][0]) swap(a[i][0],a[i-1][0]);
        }
        for(int i=1;i<=n/2;i++){
            maxn+=a[i][0];
        }
    }
    cout<<maxn;
    return 0;
}

