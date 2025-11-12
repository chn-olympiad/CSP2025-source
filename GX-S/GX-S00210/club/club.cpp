#include<bits/stdc++.h>
#include<istream>
using namespace std;
int t,n[100005],sum[100005][100005],adj[100005],my[100005][100005];
int main(){
    freopen("club.in","r",stdin);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i];
        for(int j=1;j<=n[i];j++){
            for(int l=1;l<=3;l++){
                cin>>my[j][l];
                if(j!=1&&l!=1){
                    if(my[j][l]>my[j-1][l-1]){
                        my[j][l]=sum[i][j];
                        adj[i]+=sum[i][l];
                        adj[i]=adj[i]+sum[i][j];
                    }
                }
            }
        }
        cout<<adj[i];
    }
    freopen("club.out","w",stdout);
    return 0;
}
