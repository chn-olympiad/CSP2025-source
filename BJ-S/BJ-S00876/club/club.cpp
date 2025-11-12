#include<bits/stdc++.h>
using namespace std;
int n;
int ans=INT_MIN;
vector<vector<int>> a;
//vector<vector<int>> memo;
void dfs(int steps,int val,int cnta,int cntb,int cntc){
    if(steps>n){
        ans=max(ans,val);
        return;
    }
    if(cnta<n/2){
        //if(memo[steps][0]>val+a[steps][0])return;
        //memo[steps][0]=val+a[steps][0];
        dfs(steps+1,val+a[steps][0],cnta+1,cntb,cntc);
    }if(cntb<n/2){
        //if(memo[steps][1]>val+a[steps][1])return;
        //memo[steps][1]=val+a[steps][1];
        dfs(steps+1,val+a[steps][1],cnta,cntb+1,cntc);
    }if(cntc<n/2){
        //if(memo[steps][2]>val+a[steps][2])return;
        //memo[steps][2]=val+a[steps][2];
        dfs(steps+1,val+a[steps][2],cnta,cntb,cntc+1);
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    bool flag=false;
    while(t--){
        int tmp=(flag?n:-1);
        cin>>n;
        flag=true;
        a.resize(n+1,vector<int>(3,0));
        //memo.resize(n+1,vector<int>(3,0));
//        if(tmp==n){
//            for(int i=0;i<=n;i++){
//                for(int j=0;j<3;j++){
//                    memo[i][j]=0;
//                }
//            }
//        }
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        dfs(1,0,0,0,0);
        cout<<ans<<'\n';
//        for(int i=0;i<=n;i++){
//            for(int j=0;j<3;j++){
//                cout<<memo[i][j]<<' ';
//            }
//            cout<<'\n';
//        }
        ans=INT_MIN;
    }
    return 0;

}
