#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define ll long long
struct ruji{
    int x,y,z,id;
    int fx=0,fy=0,fz=0;
}a[N];
int xs,ys,zs,x[202],y[202],z[202];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        queue<ruji> q;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
            a[i].id=i;
            q.push(a[i]);
        }
        priority_queue<int> q1,q2,q3;
        while(!q.empty()){
            ruji t=q.front();
            q.pop();
            int mx=max(t.x,max(t.y,t.z));
            if(t.fx==2&&mx==t.x){
                if(t.fy==2) mx=t.z;
                if(t.fz==2) mx=t.y;
                else mx=max(t.z,t.y);
            }else if(t.fy==2&&mx==t.y){
                if(t.fx==2) mx=t.x;
                if(t.fz==2) mx=t.y;
                else mx=max(t.x,t.z);
            }else if(t.fz==2&&mx==t.z){
                if(t.fy==2) mx=t.y;
                if(t.fx==2) mx=t.x;
                else mx=max(t.x,t.y);
            }
            if(mx==t.x&&t.fx==0){
                t.fx=1;
                q1.push(mx);
                if(q1.size()>n/2){
                    int e=q1.top();
                    q1.pop();
                    for(int i=1;i<=n;i++){
                        if(a[i].fx==1&&a[i].x==e){
                            a[i].fx=2;
                            q.push(a[i]);
                            break;
                        }
                    }
                }
            }else if(mx==t.y&&t.fy==0){
                t.fy=1;
                q2.push(t.y);
                if(q2.size()>n/2){
                    int e=q2.top();
                    q2.pop();
                    for(int i=1;i<=n;i++){
                        if(a[i].fy==1&&a[i].y==e){
                            a[i].fy=2;
                            q.push(a[i]);
                            break;
                        }
                    }
                }
            }else{
                t.fz=1;
                q3.push(mx);
                if(q3.size()>n/2){
                    int e=q3.top();
                    q3.pop();
                    for(int i=1;i<=n;i++){
                        if(a[i].fz==1&&a[i].z==e){
                            a[i].fz=2;
                            q.push(a[i]);
                            break;
                        }
                    }
                }
            }

        }
        int ans=0;
        while(!q1.empty()){
            ans+=q1.top();
            q1.pop();
        }
        while(!q2.empty()){
            ans+=q2.top();
            q2.pop();
        }
        while(!q3.empty()){
            ans+=q3.top();
            q3.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}
