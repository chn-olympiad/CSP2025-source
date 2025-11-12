#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[100005][4];
int t[4];vector<int> vec[4];
void solve(){
    cin>>n;
    for(int i=1;i<=3;i++) t[i]=0,vec[i].clear();
    for(int i=1;i<=n;i++){
        int maxn=-1,pos=0;
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
            if(a[i][j]>maxn){
                maxn=a[i][j];pos=j;
            }
        }
        t[pos]+=maxn,vec[pos].push_back(i);
    }
    int ans=0;for(int i=1;i<=3;i++) ans+=t[i];
    if(vec[1].size()>n/2){
        vector<int> v;
        for(int i:vec[1]){
            v.push_back(min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
        }
        int las=vec[1].size()-n/2;
        sort(v.begin(),v.end(),[](int x,int y){
            return x>y;
        });
        while(las--){
            ans-=v.back(),v.pop_back();
        }
    }
    else if(vec[2].size()>n/2){
        vector<int> v;
        for(int i:vec[2]){
            v.push_back(min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
        }
        int las=vec[2].size()-n/2;
        sort(v.begin(),v.end(),[](int x,int y){
            return x>y;
        });
        while(las--){
            ans-=v.back(),v.pop_back();
        }
    }
    else if(vec[3].size()>n/2){
        vector<int> v;
        for(int i:vec[3]){
            v.push_back(min(a[i][3]-a[i][2],a[i][3]-a[i][1]));
        }
        int las=vec[3].size()-n/2;
        sort(v.begin(),v.end(),[](int x,int y){
            return x>y;
        });
        while(las--){
            ans-=v.back(),v.pop_back();
        }
    }cout<<ans<<'\n';
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt;cin>>tt;
    while(tt--) solve();
}
/*
最后一次 CSPS，AK 了？人生第一次啊
CCF 别卡我常求你了

为什么在高二却输了呢。
lfxxx 24+10+5
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/