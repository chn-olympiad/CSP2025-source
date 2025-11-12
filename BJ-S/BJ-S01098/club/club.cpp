#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define fir first
#define sec second
#define mkp make_pair
using namespace std;
int t,n,a[100005][3],b[100005],to[100005],ans,cnt1,cnt2,cnt3,m;
vector<int>e;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        ans=cnt1=cnt2=cnt3=0;
        m=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
                cnt1++,ans+=a[i][1];
                b[i]=a[i][1]-max(a[i][2],a[i][3]);
                to[i]=1;
            }
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
                cnt2++,ans+=a[i][2];
                b[i]=a[i][2]-max(a[i][1],a[i][3]);
                to[i]=2;
            }
            else{
                cnt3++,ans+=a[i][3];
                b[i]=a[i][3]-max(a[i][1],a[i][2]);
                to[i]=3;
            }
        }
        if(cnt1>m){
            e.clear();
            for(int i=1;i<=n;i++){
                if(to[i]==1)e.pb(b[i]);
            }
            sort(e.begin(),e.end());
            for(auto i:e){
                if(cnt1==m)break;
                cnt1--,ans-=i;
            }
        }
        if(cnt2>m){
            e.clear();
            for(int i=1;i<=n;i++){
                if(to[i]==2)e.pb(b[i]);//,cout<<b[i]<<" ";
            }
            sort(e.begin(),e.end());
            for(auto i:e){
                if(cnt2==m)break;
                cnt2--,ans-=i;
            }
        }
        if(cnt3>m){
            e.clear();
            for(int i=1;i<=n;i++){
                if(to[i]==3)e.pb(b[i]);
            }
            sort(e.begin(),e.end());
            for(auto i:e){
                if(cnt3==m)break;
                cnt3--,ans-=i;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
