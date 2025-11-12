#include<bits/stdc++.h>
using namespace std;
// #define debug
typedef long long ll;
pair<int,int>a[100050][5];
int cnt[5];
int change[100050][4][4];
bool vis[100050];
pair<int,int>mp[100050];
int tot=0;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(vis,0,sizeof vis);
        memset(cnt,0,sizeof cnt);
        memset(mp,0,sizeof mp);
        memset(change,0,sizeof change);
        memset(a,0,sizeof a);
        tot=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1].first>>a[i][2].first>>a[i][3].first;
            a[i][1].second=1;a[i][2].second=2;a[i][3].second=3;
            for(int j=1;j<=3;j++){
                for(int k=1;k<=3;k++){
                    change[i][j][k]=a[i][j].first-a[i][k].first;
                }
            }
            sort(a[i]+1,a[i]+4,cmp);
        }
        int maxx=0,maxi=0,ans=0;
        for(int i=1;i<=n;i++){
            cnt[a[i][1].second]++;
        }
        for(int i=1;i<=3;i++){
            #ifdef debug
            cout<<cnt[i]<<" ";
            #endif
            if(maxx<cnt[i])maxi=i;
            maxx=max(cnt[i],maxx);
        }
        #ifdef debug
        cout<<endl;
        #endif
        for(int i=1;i<=n;i++)ans+=a[i][1].first;
        if(maxx<=n/2){
            cout<<ans<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            if(a[i][1].second==maxi){
                for(int j=1;j<=3;j++){
                    if(a[i][1].second==j)continue;
                    mp[++tot]={change[i][a[i][1].second][j],i};
                    #ifdef debug
                    cout<<mp[tot].first<<" "<<mp[tot].second<<endl;
                    #endif
                }
            }
        }
        sort(mp+1,mp+tot+1);
        int up=maxx-n/2;
        for(int i=1;i<=up;i++){
            if(vis[mp[i].second]){
                up++;
                continue;
            }
            vis[mp[i].second]=1;
            #ifdef debug
            cout<<mp[i].first<<" "<<mp[i].second<<endl;
            #endif
            ans-=mp[i].first;
        }
        cout<<ans<<endl;
    }
    return 0;
}