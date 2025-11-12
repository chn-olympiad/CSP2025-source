#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e5 + 100;
typedef struct Node{
    int loc;
    int x;
    int y;
    int z;
    int maxn;
}Node;
typedef struct MyRule1{
    bool operator() (Node a,Node b){
        return min(abs(a.x-a.y),abs(a.x-a.z)) > min(abs(b.x-b.y),abs(b.x-b.z));
    }
}MyRule1;
typedef struct MyRule2{
    bool operator() (Node a,Node b){
        return min(abs(a.y-a.x),abs(a.y-a.z)) > min(abs(b.y-b.z),abs(b.y-b.z));
    }
}MyRule2;
typedef struct MyRule3{
    bool operator() (Node a,Node b){
        return min(abs(a.z-a.x),abs(a.z-a.y)) > min(abs(b.z-b.x),abs(b.z-b.y));
    }
}MyRule3;
int t;
int n;
Node a[N];
priority_queue<Node,vector<Node>,MyRule1> quex;
priority_queue<Node,vector<Node>,MyRule2> quey;
priority_queue<Node,vector<Node>,MyRule3> quez;
bool mycmp(Node a,Node b){
    return a.maxn > b.maxn;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int ans = 0;
        int cnt1 = 0,cnt2 = 0,cnt3 = 0;
        cin>>n;
        for(int i = 1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            a[i].maxn = max(a[i].x,max(a[i].y,a[i].z));
            a[i].loc = i;
        }
        int m = n/2;
        sort(a+1,a+1+n,mycmp);
        for(int i = 1;i<=n;i++){
            if(a[i].x == a[i].maxn){
                if(cnt1 == m){
                    Node t = quex.top();
                    if(min(t.x-t.y,t.x-t.z)<min(a[i].x-a[i].y,a[i].x-a[i].z)){
                        quex.pop();
                        quex.push(a[i]);
                    }
                    if(t.x-t.y < t.x-t.z){
                        quey.push(t);
                    }else{
                        quez.push(t);
                    }
                }else{
                    cnt1++;
                    quex.push(a[i]);
                }                
            }else if(a[i].y == a[i].maxn){
                if(cnt2 >= m){
                    Node t = quey.top();
                    if(min(t.y-t.x,t.y-t.z)<min(a[i].y-a[i].x,a[i].y-a[i].z)){
                        quey.pop();
                        quey.push(a[i]);
                    }
                    if(t.y-t.x<t.y-t.z){
                        quex.push(t);
                    }else{
                        quez.push(t);
                    }
                }else{
                    cnt2++;
                    quey.push(a[i]);
                }                
            }else{
                if(cnt3 >= m){
                    Node t = quez.top();
                    if(min(t.z-t.x,t.z-t.y)<min(a[i].z-a[i].x,a[i].z-a[i].y)){
                        quez.pop();
                        quez.push(a[i]);
                    }
                    if(t.z-t.x<t.z-t.y){
                        quex.push(t);
                    }else{
                        quey.push(t);
                    }
                }else{
                    cnt3++;
                    quez.push(a[i]);
                }               
            }
        }
        while(!quex.empty()){
            Node t = quex.top();
            quex.pop();
        }
        while(!quex.empty()){
            Node t = quex.top();
            quex.pop();
            ans += t.x;
        }
        while(!quey.empty()){
            Node t = quey.top();
            quey.pop();
            ans += t.y;
        }
        while(!quez.empty()){
            Node t = quez.top();
            quez.pop();
            ans += t.z;
        }
        cout<<ans<<endl;
    }
    return 0;
}