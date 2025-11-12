#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,ar[100005][4],br[100005];
signed main(){
    cin>>t;
    br[0]=0;
    for(int i=1;i<=t;i++){
        cin>>n;
        memset(br,0,100004);
        for(int j=1;j<=n;j++){
            for(int k=1;k<=3;k++){
                cin>>ar[j][k];
            }
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<=3;k++){
                br[j]=max(br[j],br[j-1]+ar[j][k]);
            }
        }
        cout<<br[n]<<endl;
    }
    return 0;
}