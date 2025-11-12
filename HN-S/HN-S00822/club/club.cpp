#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+114;
int a[maxn][4],n;
int d[maxn];
int cnt[4];
void work(){
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        int mx=max(a[i][1],max(a[i][2],a[i][3]));
        if(a[i][1]==mx) d[i]=1;
        else if(a[i][2]==mx) d[i]=2;
        else d[i]=3;
        cnt[d[i]]++;
        ans+=mx;
    }
    for(int i=1;i<=3;i++){
        if(cnt[i]*2>n){
            vector<int> vec;
            for(int j=1;j<=n;j++){
                if(d[j]==i){
                    int cmx=0;
                    for(int k=1;k<=3;k++){
                        if(k!=i) cmx=max(cmx,a[j][k]);
                    }
                    vec.push_back(a[j][i]-cmx);
                }
            }
            sort(vec.begin(),vec.end());
            for(int j=0;j<cnt[i]-n/2;j++) ans-=vec[j];
        }
    }
    cout<<ans<<"\n";
    memset(a,0,sizeof(a));
    memset(d,0,sizeof(d));
    memset(cnt,0,sizeof(cnt));
    ans=0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) work();
    return 0;
}