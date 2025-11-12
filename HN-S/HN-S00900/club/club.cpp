#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int T,n,ans;
struct node{
    int c[4],mx,mx2;
}a[N];
void work(int i,int x,int y,int k1,int k2){
    if(x>=y) a[i].mx2=k1;
    else a[i].mx2=k2;
}
struct op{
    int k,pos;
    bool operator<(const op &h)const{return h.k<k;}
}num,V;
priority_queue<op> q[4];
void Clear_s(){
    for(int i=1;i<=3;i++){
        while(q[i].size()!=0) q[i].pop();
    }
    return;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].c[1]>>a[i].c[2]>>a[i].c[3];
            int x=a[i].c[1],y=a[i].c[2],z=a[i].c[3];
            if(x>=y&&x>=z){
                a[i].mx=1;
                work(i,y,z,2,3);
            }
            else if(y>=x&&y>=z){
                a[i].mx=2;
                work(i,x,z,1,3);
            }
            else{
                a[i].mx=3;
                work(i,x,y,1,2);
            }
        }
        int yp=n/2;
        for(int i=1;i<=n;i++){
            int pos1=a[i].mx,pos2=a[i].mx2;
            num.pos=i;
            num.k=a[i].c[pos1]-a[i].c[pos2];
            ans+=a[i].c[pos1];
            if(q[pos1].size()<yp) q[pos1].push(num);
            else{
                V=q[pos1].top();
                q[pos1].pop();
                int x=V.k,y=num.k;
                ans-=min(x,y);
                if(V.k<num.k){
                    q[pos1].push(num);
                    q[pos2].push(V);
                }
                else{
                    q[pos1].push(V);
                    q[pos2].push(num);
                }
            }
        }
        cout<<ans<<"\n";
        Clear_s();
    }
    return 0;
}