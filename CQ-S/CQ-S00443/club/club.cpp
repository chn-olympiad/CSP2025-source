#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define int long long
vector<int> tmp,v[3];
int t,n,ans,mid,a[N][3];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n;int mid=(n>>1);
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++)  cin>>a[i][j];
            int flag=(a[i][1]>a[i][0]);
            if(a[i][2]>a[i][flag])  flag=2;
            v[flag].push_back(i),ans+=a[i][flag];
        }
        for(int i=0;i<3;i++){
            if(v[i].size()<=mid)  continue;
            tmp.clear();
            for(auto x:v[i]){
                int ft=(i==0),se=3-i-ft;
                int to=max(a[x][ft],a[x][se]);
                tmp.push_back(a[x][i]-to);
            }
            sort(tmp.begin(),tmp.end());
            int ned=v[i].size()-mid;
            for(int j=0;j<ned;j++)  ans-=tmp[j];
        }
        cout<<ans<<"\n",ans=0;
        v[0].clear(),v[1].clear(),v[2].clear();
    }
}