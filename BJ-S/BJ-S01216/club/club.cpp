#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n,a[maxn][5],ans;
multiset<int> s[5];
int main(){
    int t;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        ans=0;
        s[1].clear();
        s[2].clear();
        s[3].clear();
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
                ans+=a[i][1];
                s[1].insert(a[i][1]-max(a[i][2],a[i][3]));
            }
            if(a[i][2]>a[i][1]&&a[i][2]>=a[i][3]){
                ans+=a[i][2];
                s[2].insert(a[i][2]-max(a[i][1],a[i][3]));
            }
            if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]){
                ans+=a[i][3];
                s[3].insert(a[i][3]-max(a[i][1],a[i][2]));
            }
        }
        while(s[1].size()>(n>>1)){
            ans-=*s[1].begin();
            s[1].erase(s[1].begin());
        }
        while(s[2].size()>(n>>1)){
            ans-=*s[2].begin();
            s[2].erase(s[2].begin());
        }
        while(s[3].size()>(n>>1)){
            ans-=*s[3].begin();
            s[3].erase(s[3].begin());
        }
        cout<<ans<<'\n';
    }
    return 0;
}
