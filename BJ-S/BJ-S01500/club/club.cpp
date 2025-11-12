#include<bits/stdc++.h>
using namespace std;
struct node{
    long long x,y,z,d;
    friend bool operator < (node a,node b){
        return a.d > b.d;
    }
};
priority_queue <node> q[4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        long long n,ans = 0;
        cin >> n;
        for(int i = 1;i <= 3;i++){
            while(q[i].size()) q[i].pop();
        }
        for(int i = 1;i <= n;i++){
            node a;
            //cin >> a.x >> a.y >> a.z;
            scanf("%lld%lld%lld",&(a.x),&(a.y),&(a.z));
            ans += max(a.x,max(a.y,a.z));
            a.d = 2 * max(a.x,max(a.y,a.z)) + min(a.x,min(a.y,a.z)) - a.x - a.y - a.z;
            if(a.x >= a.y && a.x >= a.z){
                q[1].push(a);
            }
            else if(a.y >= a.x && a.y >= a.z){
                q[2].push(a);
            }
            else{
                q[3].push(a);
            }
            //cout << ans << " ";
        }
        if(max(q[1].size(),max(q[2].size(),q[3].size())) <= n / 2){
            cout << ans << endl;
        }
        else{
            int m;
            if(q[1].size() > n / 2){
                m = 1;
            }
            else if(q[2].size() > n / 2){
                m = 2;
            }
            else{
                m = 3;
            }
            while(q[m].size() > n / 2){
                ans -= q[m].top().d;
                q[m].pop();
            }
            cout << ans << endl;
        }
    }
    return 0;
}
