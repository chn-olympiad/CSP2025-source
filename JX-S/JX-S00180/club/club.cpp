#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n;
long long ans;
int a[N][4],s[N];
vector<int> cl[4];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        for(int i=1;i<=3;i++) cl[i].clear();
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int mx=-1;
            for(int j=1;j<=3;j++) cin>>a[i][j],mx=max(mx,a[i][j]);
            if(mx==a[i][1]) cl[1].push_back(i);
            else if(mx==a[i][2]) cl[2].push_back(i);
            else cl[3].push_back(i);
            ans+=mx;
        }
        for(int j=1;j<=3;j++) if(cl[j].size()>n/2){
            int idx=0;
            for(int i=0;i<cl[j].size();i++){
                int x=cl[j][i],id,minn=2e4+5;
                for(int k=1;k<=3;k++){
                    if(k==j) continue;
                    if(a[x][j]-a[x][k]<minn) minn=a[x][j]-a[x][k],id=k;
                }
                s[++idx]=minn;
            }
            sort(s+1,s+1+idx);
            for(int i=1;i<=cl[j].size()-n/2;i++) ans-=s[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}