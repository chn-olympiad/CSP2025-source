#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n;
int a[N][3];
int f[N],g[N],ans;
int T;
bool cmp(int i,int j){
    return g[i]>g[j];
}
vector<int>has[3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(a[i][0]>=max(a[i][1],a[i][2])){
                has[0].push_back(i);
                f[i]=a[i][0];
                g[i]=f[i]-max(a[i][1],a[i][2]);
            }else if(a[i][1]>max(a[i][0],a[i][2])){
                has[1].push_back(i);
                f[i]=a[i][1];
                g[i]=f[i]-max(a[i][0],a[i][2]);
            }else{
                has[2].push_back(i);
                f[i]=a[i][2];
                g[i]=f[i]-max(a[i][1],a[i][0]);
            }
        }
        int larg=0;
        for(int i=0;i<3;i++){
            if(has[i].size()>(n>>1)){
                larg=i;
            }
        }
        sort(has[larg].begin(),has[larg].end(),cmp);
        while(has[larg].size()>(n>>1)){
            int x=has[larg].back();
            f[x]-=g[x];
            has[larg].pop_back();
        }
        ans=0;
        for(int i=1;i<=n;i++)ans+=f[i];
        for(int i=0;i<3;i++)has[i].clear();
        cout<<ans<<'\n';
    }
    return 0;
}
