#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=100005;
int T,n,p[maxn][5],th[maxn];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n;int ans=0;
        vector<int> vc[5];
        for(int i=1;i<=n;++i){
            int mx=0;th[i]=0;
            for(int j=1;j<=3;++j){
                cin>>p[i][j];
                if(!mx||p[i][mx]<p[i][j])th[i]=p[i][mx],mx=j;
                else th[i]=max(th[i],p[i][j]);
            }
            ans+=p[i][mx];
            vc[mx].push_back(p[i][mx]-th[i]);
        }
        for(int i=1;i<=3;++i)if(vc[i].size()>n/2){
            sort(vc[i].begin(),vc[i].end());
            for(int j=0;j<vc[i].size()-n/2;++j)ans-=vc[i][j];
        }
        cout<<ans<<'\n';
    }
    return 0;
}