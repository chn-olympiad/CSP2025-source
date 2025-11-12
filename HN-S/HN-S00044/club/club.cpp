#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;
int n,t,b,c,po;
struct A{
    int x,y,z,maxx;
    bool f;
}a[M],h,e;
bool cmp(const A &a,const A &b){
    if(a.x==b.x){
        return a.y>b.y;
    }
    return a.x>b.x;
}
bool Cmp(const A &a,const A &b){
    if(a.y==b.y){
        return a.z>b.z;
    }
    return a.y>b.y;
}
bool CMP(const A &a,const A &b){
    return a.z>b.z;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        h.x=0;h.y=0;h.z=0;
        cin>>n;
        po=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            a[i].maxx=max(a[i].x,max(a[i].y,a[i].z));
        }
        sort(a+1,a+1+n,cmp);

        for(int i=1;i<=n/2;i++){
            if(a[i].f!=1&&a[i].x==a[i].maxx){
                h.x+=a[i].x;
                a[i].f=1;
            }
        }
        for(int i=1;i<=n;i++){
            a[i].x=-1;
            a[i].maxx=max(a[i].y,a[i].z);
        }
        sort(a+1,a+1+n,Cmp);

        for(int i=1;i<=n/2;i++){
            if(a[i].f!=1&&a[i].y==a[i].maxx){
                h.y+=a[i].y;
                a[i].f=1;
            }
        }
        for(int i=1;i<=n;i++){
            a[i].y=-1;
            a[i].maxx=a[i].z;
        }
        sort(a+1,a+1+n,CMP);

        for(int i=1;i<=n/2;i++){
            if(a[i].f!=1&&a[i].z==a[i].maxx){
                h.z+=a[i].z;
                a[i].f=1;
            }
        }
        cout<<h.x<<' '<<h.y<<' '<<h.z<<'\n';

        for(int i=1;i<=n;i++){
            a[i].f=0;
        }
    }
    return 0;
}
