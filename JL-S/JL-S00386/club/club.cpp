#include<bits/stdc++.h>
using namespace std;
int t,n,tb,tc,td,sum;

struct stu{
    int x,y,z,p,bh;
}a[100001];
struct stut{
    int z,bh;
}b[100001];
struct stutt{
    int z,bh;
}c[100001];
struct stuttt{
    int z,bh;
}d[100001];
bool cmp_(stu a,stu b){
    return a.x>b.x;
}
bool cmp__(stu a,stu b){
    return a.y>b.y;
}
bool cmp___(stu a,stu b){
    return a.z>b.z;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        sum=0;
        tb=0;
        tc=0;
        td=0;
        for(int i=1;i<=n;i++){
            a[i].p=0;
        }
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            a[i].bh=i;
        }
        sort(a+1,a+n+1,cmp_);
        for(int i=1;i<=n;i++){
            b[i].z=a[i].x;
            b[i].bh=a[i].bh;
        }
        sort(a+1,a+n+1,cmp__);
        for(int i=1;i<=n;i++){
            c[i].z=a[i].y;
            c[i].bh=a[i].bh;
        }
        sort(a+1,a+n+1,cmp___);
        for(int i=1;i<=n;i++){
            d[i].z=a[i].z;
            d[i].bh=a[i].bh;
        }
        for(int i=1;i<=n;i++){
            if(b[i].z>=c[i].z&&b[i].z>=d[i].z&&a[b[i].bh].p!=-1&&tb<n/2){
                sum+=b[i].z;
                tb++;
                a[b[i].bh].p=-1;
            }
            if(c[i].z>=b[i].z&&c[i].z>=d[i].z&&a[c[i].bh].p!=-1&&tc<n/2){
                sum+=c[i].z;
                tc++;
                a[c[i].bh].p=-1;
            }
            if(d[i].z>=b[i].z&&d[i].z>=c[i].z&&a[d[i].bh].p!=-1&&td<n/2){
                sum+=d[i].z;
                td++;
                a[d[i].bh].p=-1;
            }

            if(tb==n/2){
                for(int i=1;i<=n;i++){
                    b[i].z=-1;
                }
            }
            if(tc==n/2){
                for(int i=1;i<=n;i++){
                    c[i].z=-1;
                }
            }
            if(td==n/2){
                for(int i=1;i<=n;i++){
                    d[i].z=-1;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
