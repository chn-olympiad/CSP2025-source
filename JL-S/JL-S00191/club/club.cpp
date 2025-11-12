#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;

int T;
int n;
struct node {
    int x,y,z;
} a[N];
priority_queue <pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > q1,q2,q3;


signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        for(int i=1;i<=n;i++){
            if(a[i].x>=a[i].y && a[i].x>=a[i].z) q1.push({min(abs(a[i].x-a[i].y),abs(a[i].x-a[i].z)),i});
            else if(a[i].y>=a[i].x && a[i].y>=a[i].z) q2.push({min(abs(a[i].x-a[i].y),abs(a[i].y-a[i].z)),i});
            else if(a[i].z>=a[i].x && a[i].z>=a[i].y) q3.push({min(abs(a[i].y-a[i].z),abs(a[i].x-a[i].z)),i});
        }
        while(q1.size()>n/2 || q2.size()>n/2 || q3.size()>n/2){
            while(!q1.empty() && q1.size()>n/2){
                if(abs(a[q1.top().second].y-a[q1.top().second].x)>abs(a[q1.top().second].z-a[q1.top().second].x)){
                    q3.push(q1.top());
                    q1.pop();
                } else {
                    q2.push(q1.top());
                    q1.pop();
                }
            }
            while(!q2.empty() && q2.size()>n/2){
                if(abs(a[q2.top().second].x-a[q2.top().second].y)>abs(a[q1.top().second].z-a[q1.top().second].y)){
                    q3.push(q2.top());
                    q2.pop();
                } else {
                    q1.push(q2.top());
                    q2.pop();
                }
            }
            while(!q3.empty() && q3.size()>n/2){
                if(abs(a[q3.top().second].y-a[q3.top().second].z)>abs(a[q3.top().second].x-a[q3.top().second].z)){
                    q1.push(q3.top());
                    q3.pop();
                } else {
                    q2.push(q3.top());
                    q3.pop();
                }
            }
        }
        long long ans=0;
        while(!q1.empty()){
            ans+=a[q1.top().second].x;
            q1.pop();
        }
        while(!q2.empty()){
            ans+=a[q2.top().second].y;
            q2.pop();
        }
        while(!q3.empty()){
            ans+=a[q3.top().second].z;
            q3.pop();
        }
        cout<<ans<<"\n";
    }
    return 0;
}