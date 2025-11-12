#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll Ans;
int c1,c2,c3,n,d[N][5],pref[N];
inline void solve(){
    cin>>n;c1=c2=c3=Ans=0;
    for(int i=1;i<=n;i++){
        cin>>d[i][1]>>d[i][2]>>d[i][3];
        int mx=max({d[i][1],d[i][2],d[i][3]});
        if(mx==d[i][1]){
            c1++;pref[i]=1;
            Ans+=d[i][1];
        }else if(mx==d[i][2]){
            c2++;pref[i]=2;
            Ans+=d[i][2];
        }else{
            c3++;pref[i]=3;
            Ans+=d[i][3];
        }
    }
    if(max({c1,c2,c3})>n/2){
        vector<int>vec;int cmx=max({c1,c2,c3})-n/2;
        if(c1>n/2){
            for(int i=1;i<=n;i++){
                if(pref[i]==1){
                    vec.push_back(max(d[i][2]-d[i][1],d[i][3]-d[i][1]));
                }
            }
        }else if(c2>n/2){
            for(int i=1;i<=n;i++){
                if(pref[i]==2){
                    vec.push_back(max(d[i][1]-d[i][2],d[i][3]-d[i][2]));
                }
            }            
        }else{
            for(int i=1;i<=n;i++){
                if(pref[i]==3){
                    vec.push_back(max(d[i][1]-d[i][3],d[i][2]-d[i][3]));
                }
            }
        }sort(vec.begin(),vec.end());
        while(cmx){
            Ans+=vec.back();
            vec.pop_back();
            cmx--;
        }cout<<Ans<<endl;
    }else{
        cout<<Ans<<endl;
    }
}
signed main(){
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
}