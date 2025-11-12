#include<bits/stdc++.h>

using namespace std;
const int N=1e5+5;
long long t,n,a[N][3],dp[N],ans;
priority_queue<int> q[3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        memset(q,0,sizeof(q));
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                q[j].push(a[i][j]);
            }

        }
        if(a[n][2]==0&&a[n][3]==0){
            for(int i=1;i<=(n>>1);i++){
                ans+=q[1].top();
                q[1].pop();
            }
        }else{

            for(int i=1;i<=(n>>1);i++){
                ans+=q[1].top()+q[2].top();
                q[1].pop();q[2].pop();
            }


        }
        cout<<ans<<endl;


    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
