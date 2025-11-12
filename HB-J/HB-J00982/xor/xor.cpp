#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],v,vis[500005],cs;
vector<pair<int,int> >s;
int dfs(int ci,int c){
    if(ci==cs)return c;
    int m=dfs(ci+1,c);
    for(int i=s[ci].first;i<=s[ci].second;i++)if(vis[i])return m;
    for(int i=s[ci].first;i<=s[ci].second;i++)vis[i]=1;
    int ce=0;
    for(int i=0;i<cs;i++)ce+=!vis[i];
    if(ce<(s[ci].second-s[ci].first)){
        for(int i=s[ci].first;i<=s[ci].second;i++)vis[i]=0;
        return m;
    }m=max(m,dfs(ci+1,c+1));
    for(int i=s[ci].first;i<=s[ci].second;i++)vis[i]=0;
    return m;
}bool cmp(pair<int,int>a,pair<int,int>b){return (a.second-a.first)>(b.second-b.first);}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            v=a[i];
            for(int ij=i+1;ij<=j;ij++)v^=a[ij];
            if(v==k)s.push_back(make_pair(i,j)),cs++;
        }
    }sort(s.begin(),s.end(),cmp);
    printf("%d",dfs(0,0));
    return 0;
}
