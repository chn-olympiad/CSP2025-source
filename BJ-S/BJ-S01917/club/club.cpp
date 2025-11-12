#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N=100005;

int arr[N][5];
vector<int> d[5];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;
    cin>>t;
    while(t--){
        for(int i=1;i<=3;++i){
            d[i].clear();
        }
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;++i){
            int mxid=0;
            for(int j=1;j<=3;++j){
                cin>>arr[i][j];
                if(arr[i][j]>=arr[i][mxid]){
                    mxid=j;
                }
            }ans+=arr[i][mxid];
            int mx2id=0;
            for(int j=1;j<=3;++j){
                if(j==mxid) continue;
                if(arr[i][j]>=arr[i][mx2id]){
                    mx2id=j;
                }
            }d[mxid].push_back(arr[i][mx2id]-arr[i][mxid]);
            //cout<<i<<' '<<mxid<<' '<<mx2id<<endl;
        }
        for(int i=1;i<=3;++i){
            sort(d[i].begin(),d[i].end(),greater<int>());
            for(int j=0;j<(long long)(d[i].size())-n/2;++j){
                ans+=d[i][j];
                //cout<<i<<' '<<j<<' '<<d[i][j]<<'\n';
            }
        }cout<<ans<<'\n';
    }
    return 0;
}
