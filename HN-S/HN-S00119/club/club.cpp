#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define INF 2000000000

int T,n,a[100005][3],pos[100005],cnt[3],res;
vector<int>v;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n,cnt[0]=cnt[1]=cnt[2]=0,res=0;
        for(rint i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])pos[i]=0,cnt[0]++,res+=a[i][0];
            else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])pos[i]=1,cnt[1]++,res+=a[i][1];
            else pos[i]=2,cnt[2]++,res+=a[i][2];
        }
        rint x=0;
        if(cnt[1]>cnt[x])x=1;
        if(cnt[2]>cnt[x])x=2;
        v.clear();
        for(rint i=1;i<=n;i++){
            if(pos[i]==x){
                rint mx=-INF;
                for(rint j=0;j<=2;j++){
                    if(j==x)continue;
                    mx=max(mx,a[i][j]-a[i][x]);
                }
                v.push_back(mx);
            }
        }
        sort(v.begin(),v.end()),reverse(v.begin(),v.end());
        for(rint i=0;i<cnt[x]-n/2;i++)res+=v[i];
        cout<<res<<"\n";
    }
    return 0;
}