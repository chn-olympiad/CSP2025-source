#include<bits/stdc++.h>
using namespace std;
int T;
int n,k,ans;
int s,t1,t2,cnt,f;
int a[5][100005],vis[100005];
vector<int> v[5];
struct St{
    int id,val;
};
vector<St> st;
bool cmp(St a,St b){
    return a.val<b.val;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        k=n/2,ans=0,cnt=0,f=0,s=0,t1=0,t2=0;
        v[1].clear(),v[2].clear(),v[3].clear(),st.clear();
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
            if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i]) ans+=a[1][i],v[1].push_back(i);
            else if(a[2][i]>=a[1][i]&&a[2][i]>=a[3][i]) ans+=a[2][i],v[2].push_back(i);
            else if(a[3][i]>=a[1][i]&&a[3][i]>=a[2][i]) ans+=a[3][i],v[3].push_back(i);
        }
        if(v[1].size()<=k&&v[2].size()<=k&&v[3].size()<=k){
            printf("%d\n",ans);
            continue;
        }
        if(v[1].size()>k) s=1,t1=2,t2=3;
        if(v[2].size()>k) s=2,t1=1,t2=3;
        if(v[3].size()>k) s=3,t1=1,t2=2;
        for(int i=0;i<v[s].size();i++){
            st.push_back(St{v[s][i],a[s][v[s][i]]-a[t1][v[s][i]]});
            st.push_back(St{v[s][i],a[s][v[s][i]]-a[t2][v[s][i]]});
        }
        cnt=v[s].size()-k;
        sort(st.begin(),st.end(),cmp);
        while(cnt){
            while(vis[st[f].id]){
                f++;
            }
            vis[st[f].id]=1;
            ans-=st[f].val,f++,cnt--;
        }
        printf("%d\n",ans);
    }
    return 0;
}
