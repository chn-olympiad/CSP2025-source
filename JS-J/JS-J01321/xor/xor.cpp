#include<bits/stdc++.h>
using namespace std;
int n,k,a[500666],s[500666],id[500666];
set<pair<int,int>>st;
map<int,int>mp;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    mp[0]=-1;
    for (int i=1;i<=n;i++){
       s[i]=(s[i-1]^a[i]);
       int x=(s[i]^k);
       if (x==0&&mp[x]==-1) id[0]=i,mp[x]=0;
       else if (mp[x]!=0&&id[mp[x]]==0) id[mp[x]]=i;
       mp[s[i]]=i;
    }
    for (int i=0;i<=n;i++) if (id[i]!=0) st.insert({id[i],i+1});
    int ans=0,r=0;
    for (auto i:st){
        if (i.second<=r) continue;
        else ++ans,r=i.first;
    }
    printf("%d\n",ans);
    return 0;
}
