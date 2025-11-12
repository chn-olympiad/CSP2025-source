#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int w[N][3];
int n;
int chc[N];
int minu[N];
priority_queue<int,vector<int>,greater<int>>q[3];
int gem(int i,int x,int y){
    if(w[i][x]>w[i][y]){
        return x;
    }else{
        return y;
    }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                cin>>w[i][j];
            }
            minu[i]=gem(i,0,gem(i,2,1));
            chc[i]=1e9+9;
            for(int k=0;k<3;k++){
                if(k!=minu[i]){
                    chc[i]=min(chc[i],w[i][minu[i]]-w[i][k]);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(q[minu[i]].size()<n/2){
                q[minu[i]].push(chc[i]);
                ans+=w[i][minu[i]];
            }else{
                if(q[minu[i]].top()<chc[i]){
                    ans-=q[minu[i]].top();
                    ans+=w[i][minu[i]];
                    q[minu[i]].push(chc[i]);
                    q[minu[i]].pop();
                }else{
                    ans+=w[i][minu[i]]-chc[i];
                }
            }
        }
        for(int i=0;i<3;i++){
            while(!q[i].empty())q[i].pop();
        }
        cout<<ans<<endl;
    }


    return 0;
}