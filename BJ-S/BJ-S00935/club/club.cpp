#include <bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
#define endl "\n"
#define print(x) cerr<<#x<<"="<<x<<"\n"
#define dbg() cerr<<"LINE "<<__LINE__<<"\n"
using namespace std;
const int inf=1e18;
int cur=-1,ans,n,a[111111][5];
vector<int> v[5];
bool cmp(int x,int y){
    int tmp1=inf,tmp2=inf;
    for(int i=1;i<=3;i++){
        if(i==cur)continue;
        tmp1=min(tmp1,a[x][cur]-a[x][i]);
        tmp2=min(tmp2,a[y][cur]-a[y][i]);
    }
    return tmp1>tmp2;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    //14:50 AC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        for(int i=1;i<=3;i++){
            v[i].clear();
        }
        ans=0;
        cur=-1;
        cin>>n;
        for(int i=1;i<=n;i++){
            int mx=-inf,mxp;
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                if(a[i][j]>mx){
                    mx=a[i][j];
                    mxp=j;
                }
            }
            v[mxp].push_back(i);
        }
        for(int i=1;i<=3;i++){
            if(v[i].size()>n/2){
                cur=i;
            }
        }
        for(int i=1;i<=3;i++){
            for(auto j:v[i]){
                ans+=a[j][i];
            }
        }
        if(cur==-1){
            cout<<ans<<"\n";
            continue;
        }
        sort(v[cur].begin(),v[cur].end(),cmp);
        while(v[cur].size()>n/2){
            int x=v[cur][v[cur].size()-1],mn=inf;
            for(int i=1;i<=3;i++){
                if(i==cur)continue;
                mn=min(mn,a[x][cur]-a[x][i]);
            }
            ans-=mn;
            v[cur].pop_back();
        }
        cout<<ans<<"\n";
    }
    return 0;
}
