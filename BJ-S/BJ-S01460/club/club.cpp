#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[100005][3];
int p[100005];
bool cmp(int x,int y){
    return a[x][2].first-a[x][1].first>a[y][2].first-a[y][1].first;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--){
        int n,cnt[3]={},ans=0;cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++) cin>>a[i][j].first,a[i][j].second=j;
            sort(a[i],a[i]+3),p[i]=i;
        }
        sort(p+1,p+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(cnt[a[p[i]][2].second]==n/2) cnt[a[p[i]][1].second]++,ans+=a[p[i]][1].first;
            else cnt[a[p[i]][2].second]++,ans+=a[p[i]][2].first;
        }
        cout<<ans<<'\n';
    }
}