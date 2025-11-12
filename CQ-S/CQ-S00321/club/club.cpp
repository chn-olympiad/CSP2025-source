#include<bits/stdc++.h>
#define int long long
using namespace std;
priority_queue<int> pq[3];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int ans=0;
        while(!pq[1].empty()){
            pq[1].pop();
        }
        while(!pq[0].empty()){
            pq[0].pop();
        }
        while(!pq[2].empty()){
            pq[2].pop();
        }
        for(int i=1;i<=n;i++){
            int a1,a2,a3;
            cin>>a1>>a2>>a3;
            if(a3>=a2&&a3>=a1){
                ans+=a3;
                pq[2].push(max(a2-a3,a1-a3));
                
            }
            else if(a2>=a1&&a2>=a3){
                ans+=a2;
                pq[1].push(max(a1-a2,a3-a2));
            }
            else{
                ans+=a1;
                pq[0].push(max(a2-a1,a3-a1));
            }
        }
        if(pq[0].size()>n/2){
            while(pq[0].size()>n/2){
                ans+=pq[0].top();
                pq[0].pop();
            }
        }
        else if(pq[1].size()>n/2){
            while(pq[1].size()>n/2){
                ans+=pq[1].top();
                pq[1].pop();
            }
        }
        else{
            while(pq[2].size()>n/2){
                ans+=pq[2].top();
                pq[2].pop();
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
