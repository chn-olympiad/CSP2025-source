#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int sz[4];
priority_queue<int,vector<int>,greater<int> > q[4];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        for(int i=1;i<=3;i++){
            while(!q[i].empty())q[i].pop();
        }
        sz[1]=sz[2]=sz[3]=0;
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            if(a>=b&&a>=c){
                q[1].push(a-max(b,c));
                sz[1]++;
                ans+=a;
            }
            else if(b>=a&&b>=c){
                q[2].push(b-max(a,c));
                sz[2]++;
                ans+=b;
            }
            else{
                q[3].push(c-max(b,a));
                sz[3]++;
                ans+=c;
            }
        }
        for(int i=1;i<=3;i++){
            while(sz[i]>n/2){
                sz[i]--;
                ans-=q[i].top();
                q[i].pop();
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
