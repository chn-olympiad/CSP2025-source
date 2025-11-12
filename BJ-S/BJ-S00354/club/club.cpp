#include<bits/stdc++.h>
using namespace std;
int a[100005][3];
vector<int> ps[3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            int maxn=max(max(a[i][0],a[i][1]),a[i][2]);
            if(a[i][0]==maxn){
                ps[0].push_back(min(maxn-a[i][1],maxn-a[i][2]));
                ans+=maxn;
            }else if(a[i][1]==maxn){
                ps[1].push_back(min(maxn-a[i][0],maxn-a[i][2]));
                ans+=maxn;
            }else{
                ps[2].push_back(min(maxn-a[i][1],maxn-a[i][0]));
                ans+=maxn;
            }
        }
        for(int i=0;i<3;i++){
            if(ps[i].size()>n/2){
                sort(ps[i].begin(),ps[i].end());
                for(int j=0;j<ps[i].size()-n/2;j++){
                    ans-=ps[i][j];
                }
                break;
            }
        }
        cout<<ans<<endl;
        for(int i=0;i<3;i++){
            ps[i].clear();
        }
    }
    return 0;
}
