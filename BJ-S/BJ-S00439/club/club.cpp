#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+1;
int T,n,a[N][3],ans=0,pos[N],rt[3],top=0;
pair<pair<int,int>,pair<int,int>>st[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        rt[0]=rt[1]=rt[2]=0;
        cin>>n;
        for(int i=1;i<=n;i++)for(int j=0;j<3;j++)cin>>a[i][j];
        for(int i=1;i<=n;i++){
            auto g=max_element(a[i],a[i]+3);
            ans+=*g;
            rt[pos[i]=g-a[i]]++;
        }
        top=0;
        if(rt[0]>n/2){
            for(int i=1;i<=n;i++){
                if(pos[i]==0){
                    st[++top]={{a[i][0]-max(a[i][1],a[i][2]),a[i][0]-min(a[i][1],a[i][2])},{i,(a[i][1]<a[i][2]?2:1)}};
                }
            }
            sort(st+1,st+top+1);
            for(int i=1;i<=top-n/2;i++){
                rt[0]--;
                rt[pos[st[i].second.first]=st[i].second.second]++;
                ans-=st[i].first.first;
            }
        }else if(rt[1]>n/2){
            for(int i=1;i<=n;i++){
                if(pos[i]==1){
                    st[++top]={{a[i][1]-max(a[i][0],a[i][2]),a[i][1]-min(a[i][0],a[i][2])},{i,(a[i][0]<a[i][2]?2:0)}};
                }
            }
            sort(st+1,st+top+1);
            for(int i=1;i<=top-n/2;i++){
                rt[1]--;
                rt[pos[st[i].second.first]=st[i].second.second]++;
                ans-=st[i].first.first;
            }
        }else if(rt[2]>n/2){
            for(int i=1;i<=n;i++){
                if(pos[i]==2){
                    st[++top]={{a[i][2]-max(a[i][0],a[i][1]),a[i][2]-min(a[i][0],a[i][1])},{i,(a[i][0]<a[i][1]?1:0)}};
                }
            }
            sort(st+1,st+top+1);
            for(int i=1;i<=top-n/2;i++){
                rt[2]--;
                rt[pos[st[i].second.first]=st[i].second.second]++;
                ans-=st[i].first.first;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}