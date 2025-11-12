#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][3],cnt[3];
vector<int> g[3],tmp;
int ans;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        memset(cnt,0,sizeof(cnt));
        g[0].clear(),g[1].clear(),g[2].clear(),tmp.clear();
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
            if(a[i][0]>=max(a[i][1],a[i][2]))cnt[0]++,g[0].push_back(i);
            else if(a[i][1]>=max(a[i][0],a[i][2]))cnt[1]++,g[1].push_back(i);
            else cnt[2]++,g[2].push_back(i);
            ans+=max(max(a[i][1],a[i][2]),a[i][0]);
        }
        if(max(max(cnt[1],cnt[2]),cnt[0])<=n/2){
            cout<<ans<<endl;
            continue;
        }
        int idx=0;
        for(int i=0;i<3;i++)if(cnt[idx]<cnt[i])idx=i;
        for(int i=0;i<g[idx].size();i++){
            int maxn=0;
            for(int j=0;j<3;j++){
                if(j==idx)continue;
                maxn=max(maxn,a[g[idx][i]][j]);
            }
            //cout<<a[g[idx][i]][idx]<<" "<<maxn<<endl;
            tmp.push_back(a[g[idx][i]][idx]-maxn);
        }
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<cnt[idx]-n/2;i++)ans-=tmp[i];//,cout<<tmp[i]<<endl;
        cout<<ans<<endl;
    }
    return 0;
}
//Ren5Jie4Di4Ling5%
