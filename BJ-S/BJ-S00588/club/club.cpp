#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][3],ans;
vector<int> v[3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        v[0].clear(),v[1].clear(),v[2].clear();
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            int x=max(max(a[i][0],a[i][1]),a[i][2]);
            ans+=x;
            if(x==a[i][0]) v[0].push_back(min(a[i][0]-a[i][1],a[i][0]-a[i][2]));
            else if(x==a[i][1]) v[1].push_back(min(a[i][1]-a[i][0],a[i][1]-a[i][2]));
            else v[2].push_back(min(a[i][2]-a[i][0],a[i][2]-a[i][1]));
        }
        for(int i=0;i<3;i++){
            int m=(int)v[i].size();
            if(m>n/2){
                sort(v[i].begin(),v[i].end());
                for(int j=0;j<m-n/2;j++) ans-=v[i][j];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}