#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
void solve(){
    int ans=0;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>>s1,s2,s3;
    for(int i=1,x,y,z;i<=n;i++){
        cin>>x>>y>>z;
        if(x>=y&&x>=z){
            int sec=max(y,z);
            ans+=x;
            s1.push(x-sec);
            if(s1.size()>n/2)ans-=s1.top(),s1.pop();
        }else if(y>=x&&y>=z){
            int sec=max(x,z);
            ans+=y;
            s2.push(y-sec);
            if(s2.size()>n/2)ans-=s2.top(),s2.pop();
        }else if(z>=x&&z>=y){
            int sec=max(x,y);
            ans+=z;
            s3.push(z-sec);
            if(s3.size()>n/2)ans-=s3.top(),s3.pop();
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)solve();
    return 0;
}
