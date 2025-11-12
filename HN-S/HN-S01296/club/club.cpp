#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> vec[5];
int a[200005][5];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        vec[1].clear();
        vec[2].clear();
        vec[3].clear();
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            a[i][1]=a[i][2]=a[i][3]=0;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
                ans+=a[i][1];
                vec[1].push_back(max(a[i][2]-a[i][1],a[i][3]-a[i][1]));
            }else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
                ans+=a[i][2];
                vec[2].push_back(max(a[i][1]-a[i][2],a[i][3]-a[i][2]));
            }else{
                ans+=a[i][3];
                vec[3].push_back(max(a[i][1]-a[i][3],a[i][2]-a[i][3]));
            }
        }
        sort(vec[1].begin(),vec[1].end());
        reverse(vec[1].begin(),vec[1].end());
        sort(vec[2].begin(),vec[2].end());
        reverse(vec[2].begin(),vec[2].end());
        sort(vec[3].begin(),vec[3].end());
        reverse(vec[3].begin(),vec[3].end());
        int len=n/2;
        if(vec[1].size()>len){
            int N=vec[1].size();
            N-=len;
            for(int i=0;i<N;i++){
                ans+=vec[1][i];
            }
        }
        if(vec[2].size()>len){
            int N=vec[2].size();
            N-=len;
            for(int i=0;i<N;i++){
                ans+=vec[2][i];
            }
        }
        if(vec[3].size()>len){
            int N=vec[3].size();
            N-=len;
            for(int i=0;i<N;i++){
                ans+=vec[3][i];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}