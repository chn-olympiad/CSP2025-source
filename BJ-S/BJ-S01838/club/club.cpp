#include<bits/stdc++.h>

using namespace std;
using ll=long long;
using vi=vector<int>;

const int N=1e5+10;

int t,n,a[N][3];
ll ans=0;
priority_queue<int> pq1,pq2,pq3;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;++i){cin>>a[i][0]>>a[i][1]>>a[i][2];}
        for(int i=1;i<=n;++i){
            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
                pq1.push(max(a[i][1],a[i][2])-a[i][0]);
                ans+=a[i][0];
            }
            else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
                pq2.push(max(a[i][0],a[i][2])-a[i][1]);
                ans+=a[i][1];
            }
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][0]){
                pq3.push(max(a[i][1],a[i][0])-a[i][2]);
                ans+=a[i][2];
            }
        }
        // cout<<ans<<' '<<cnt1<<' '<<cnt2<<' '<<cnt3<<'\n';
        while(pq1.size()>n/2){ans+=pq1.top();pq1.pop();}
        while(pq2.size()>n/2){ans+=pq2.top();pq2.pop();}
        while(pq3.size()>n/2){ans+=pq3.top();pq3.pop();}
        while(pq1.size()){pq1.pop();}
        while(pq2.size()){pq2.pop();}
        while(pq3.size()){pq3.pop();}
        cout<<ans<<'\n';
    }

    return 0;
}