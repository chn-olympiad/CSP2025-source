#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[100100][4];
int ans=-99;
void bfs(int ren,int s1,int s1r,int s2,int s2r,int s3,int s3r){

    if(s1r<=n/2&&s2r<=n/2&&s3r<=n/2){
        if(ren<n){
            bfs(ren+1,s1+a[ren+1][1],s1r+1,s2,s2r,s3,s3r);
            bfs(ren+1,s1,s1r,s2+a[ren+1][2],s2r+1,s3,s3r);
            bfs(ren+1,s1,s1r,s2,s2r,s3+a[ren+1][3],s3r+1);
        }
        else ans=max(ans,s1+s2+s3);

    }


}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int _;
    cin>>_;
    while(_--){


        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        ans=-99;
        bfs(1,a[1][1],1,0,0,0,0);
        bfs(1,0,0,a[1][2],1,0,0);
        bfs(1,0,0,0,0,a[1][3],1);
        cout<<ans<<endl;
    }
    return 0;

}
