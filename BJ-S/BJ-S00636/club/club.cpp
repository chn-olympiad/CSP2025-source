#include<bits/stdc++.h>
using namespace std;
const int MAXN=500000+2;
long long T,n,a[MAXN][4],ans,sum[5],ma;
bool flag[5];
vector<long long>p[5],s;
void solve(){
    ans=0;s.clear();
    for(long long i=0;i<5;i++){
        sum[i]=flag[i]=0;p[i].clear();
    }
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        ma=max(a[i][1],max(a[i][2],a[i][3]));
        ans+=ma;
        a[i][1]-=ma;a[i][2]-=ma;a[i][3]-=ma;
        for(long long j=1;j<=3;j++)
            if(a[i][j]==0){
                sum[j]++;
                p[j].push_back(i);
                break;
            }
    }
    if(sum[1]>=sum[2]&&sum[1]>=sum[3]){
        if(sum[1]<=n/2){
            cout<<ans<<endl;
            return;
        }
        for(auto y:p[1]){
            if(a[y][1]-a[y][2]<a[y][1]-a[y][3])
                s.push_back(a[y][1]-a[y][2]);
            else
                s.push_back(a[y][1]-a[y][3]);
        }
        sort(s.begin(),s.end());
        for(auto y:s){
            if(sum[1]==n/2)
                break;
            ans-=y;
            sum[1]--;
        }
        cout<<ans<<endl;
    }
    else if(sum[2]>=sum[1]&&sum[2]>=sum[3]){
        if(sum[2]<=n/2){
            cout<<ans<<endl;
            return;
        }
        for(auto y:p[2]){
            if(a[y][2]-a[y][1]<a[y][2]-a[y][3])
                s.push_back(a[y][2]-a[y][1]);
            else
                s.push_back(a[y][2]-a[y][3]);
        }
        sort(s.begin(),s.end());
        for(auto y:s){
            if(sum[2]==n/2)
                break;
            ans-=y;
            sum[2]--;
        }
        cout<<ans<<endl;
    }else{
        if(sum[3]<=n/2){
            cout<<ans<<endl;
            return;
        }
        for(auto y:p[3]){
            if(a[y][3]-a[y][1]<a[y][3]-a[y][2])
                s.push_back(a[y][3]-a[y][1]);
            else
                s.push_back(a[y][3]-a[y][2]);
        }
        sort(s.begin(),s.end());
        for(auto y:s){
            if(sum[3]==n/2)
                break;
            ans-=y;
            sum[3]--;
        }
        cout<<ans<<endl;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
