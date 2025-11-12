#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t>>n;
    int ans=0;
    int a[100000][10];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
            if(a[i][j]<=n/2){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}

