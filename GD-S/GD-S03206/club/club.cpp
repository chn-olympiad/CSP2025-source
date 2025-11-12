#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a,b,c,ans;
struct X{int x,y,z;friend bool operator<(X p,X q){return max(p.y,p.z)-p.x<max(q.y,q.z)-q.x;}};
struct Y{int x,y,z;friend bool operator<(Y p,Y q){return max(p.x,p.z)-p.y<max(q.x,q.z)-q.y;}};
struct Z{int x,y,z;friend bool operator<(Z p,Z q){return max(p.x,p.y)-p.z<max(q.x,q.y)-q.z;}};
priority_queue<X>x;
priority_queue<Y>y;
priority_queue<Z>z;
int main(){
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n,ans=0;
        for(int i=1;i<=n;i++){
            cin>>a>>b>>c;
            int mx=max({a,b,c});
            if(a==mx){
                if(x.size()*2<n) x.push({a,b,c});
                else{
                    X t=x.top();
                    if(max(b,c)-a<max(t.y,t.z)-t.x){
                        x.pop(),x.push({a,b,c});
                        if(t.y>t.z) y.push({t.x,t.y,t.z});
                        else z.push({t.x,t.y,t.z});
                    }else if(b>c) y.push({a,b,c});
                    else z.push({a,b,c});
                }
            }else if(b==mx){
                if(y.size()*2<n) y.push({a,b,c});
                else{
                    Y t=y.top();
                    if(max(a,c)-b<max(t.x,t.z)-t.y){
                        y.pop(),y.push({a,b,c});
                        if(t.x>t.z) x.push({t.x,t.y,t.z});
                        else z.push({t.x,t.y,t.z});
                    }else if(a>c) x.push({a,b,c});
                    else z.push({a,b,c});
                }
            }else{
                if(z.size()*2<n) z.push({a,b,c});
                else{
                    Z t=z.top();
                    if(max(a,b)-c<max(t.x,t.y)-t.z){
                        z.pop(),z.push({a,b,c});
                        if(t.x>t.y) x.push({t.x,t.y,t.z});
                        else y.push({t.x,t.y,t.z});
                    }else if(a>b) x.push({a,b,c});
                    else y.push({a,b,c});
                }
            }
        }
        while(!x.empty()) ans+=x.top().x,x.pop();
        while(!y.empty()) ans+=y.top().y,y.pop();
        while(!z.empty()) ans+=z.top().z,z.pop();
        cout<<ans<<'\n';
    }
    return 0;
}