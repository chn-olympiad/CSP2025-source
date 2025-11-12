#include<bits/stdc++.h>
using namespace std;
struct nude{
    int x,y,z;
}a[100100];
int dpx[1001000],dpy[10010000],dpz[10010000];
int xx=0,yy=0,zz=0;
int n;
int maxx=-1;
int cmp(nude aa,nude bb){
    return aa.y>bb.y;
}
int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(dpx,0,sizeof(0));
        memset(dpy,0,sizeof(0));
        memset(dpz,0,sizeof(0));
        cin>>n;
        for(int i=1;i<=n;i++){
            bool boo=true;
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(xx!=n/2+1) {
                if(dpx[i-1]<dpx[i-1]+a[i].x){
                    dpx[i]=max(dpx[i-1],dpx[i-1]+a[i].x);
                    xx++;
                    boo=false;
                }
                else dpx[i]=max(dpx[i-1],dpx[i-1]+a[i].x);

            }
            if(yy!=n/2+1&&boo) {
                if(dpy[i-1]<dpy[i-1]+a[i].y){
                    dpy[i]=max(dpy[i-1],dpy[i-1]+a[i].y);
                    yy++;
                    boo=false;
                }
                else dpy[i]=max(dpy[i-1],dpy[i-1]+a[i].y);
            }
            if(zz!=n/2+1&&boo) {
                if(dpz[i-1]<dpz[i-1]+a[i].z){
                    dpz[i]=max(dpz[i-1],dpz[i-1]+a[i].z);
                    zz++;
                }
                else dpz[i]=max(dpz[i-1],dpz[i-1]+a[i].z);
            }
        }
        cout<<dpx[xx-1]+dpy[yy-1]+dpz[zz-1];
    }
    return 0;
}
