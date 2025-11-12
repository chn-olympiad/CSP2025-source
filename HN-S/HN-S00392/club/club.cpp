#include<bits/stdc++.h>
using namespace std;
int n;
typedef long long at;
const int N=1e5+5;
at a[N][3];
int cnt[3];
vector<at>imxj[3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Ts;
    at ans;
    int jmxcnt;
    for(cin>>Ts;Ts;--Ts){
        cin>>n;
        cnt[0]=cnt[1]=cnt[2]=0;
        ans=0;
        imxj[0].clear();imxj[1].clear();imxj[2].clear();
        imxj[0].shrink_to_fit();imxj[1].shrink_to_fit();imxj[2].shrink_to_fit();
        for(int i=1;i<=n;++i){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
                ++cnt[0];
                ans+=a[i][0];
                imxj[0].push_back(a[i][0]-max(a[i][1],a[i][2]));
            }
            else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
                ++cnt[1];
                ans+=a[i][1];
                imxj[1].push_back(a[i][1]-max(a[i][0],a[i][2]));
            }
            else{
                ++cnt[2];
                ans+=a[i][2];
                imxj[2].push_back(a[i][2]-max(a[i][0],a[i][1]));
            }
        }
        jmxcnt=0;
        if(cnt[1]>cnt[jmxcnt]){
            jmxcnt=1;
        }
        if(cnt[2]>cnt[jmxcnt]){
            jmxcnt=2;
        }
        if(cnt[jmxcnt]<=(n>>1)){
            cout<<ans<<'\n';
            continue;
        }
        sort(imxj[jmxcnt].begin(),imxj[jmxcnt].end());
        for(at i:imxj[jmxcnt]){
            --cnt[jmxcnt];
            ans-=i;
            if(cnt[jmxcnt]<=(n>>1)){
                break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}