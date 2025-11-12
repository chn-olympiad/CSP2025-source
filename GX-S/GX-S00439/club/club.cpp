#include<bits/stdc++.h>
using namespace std;
int n,T;
struct node{
    int x,y,z,maxn;
}a[10001];
int cmpx(node g,node h){
    return g.x>h.x;
}
int cmpy(node g,node h){
    return g.y>h.y;
}
int cmpz(node g,node h){
    return g.z>h.z;
}
int cmp1(node g,node h){
    if(g.x>max(g.y,g.z)&&(h.x>max(h.y,h.z))) {
        return g.x-max(g.y,g.z)<h.x-max(h.y,h.z);
    }
}
int cmp2(node g,node h){
    if(g.y>max(g.x,g.z)&&h.y>max(h.x,h.z)){
        return g.y-max(g.x,g.z)<h.y-max(h.x,h.z);
    }
}
int cmp3(node g,node h){
    if(g.z>max(g.x,g.y)&&h.z>max(h.x,h.y)){
        return g.z-max(g.x,g.y)<h.z-max(h.x,h.y);
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for(int k=1;k<=T;k++){
        cin>>n;
        memset(a,0,sizeof(a));
        int xx=0,yy=0,zz=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].x>a[i].y&&a[i].x>a[i].z){
                xx++;
                a[i].maxn=a[i].x;
            }else if(a[i].y>a[i].x&&a[i].y>a[i].z){
                yy++;
                a[i].maxn=a[i].y;
            }else if(a[i].z>a[i].y&&a[i].z>a[i].x){
                zz++;
                a[i].maxn=a[i].z;
            }else{
                xx++;
                a[i].maxn=a[i].x;
            }
        }int u=0;
        if(xx>n/2){
            sort(a+1,a+n,cmpx);
            sort(a+1,a+xx,cmp1);
            for(int i=1;i<=xx-n/2;i++) u+=max(a[i].y,a[i].z);
            for(int i=xx-n/2+1;i<=n;i++) u+=a[i].maxn;
        }else if(yy>n/2){
            sort(a+1,a+n,cmpy);
            sort(a+1,a+yy,cmp2);
            for(int i=1;i<=yy-n/2;i++) u+=max(a[i].x,a[i].z);
            for(int i=yy-n/2+1;i<=n;i++) u+=a[i].maxn;

        }else if(zz>n/2){
            sort(a+1,a+n,cmpz);
            sort(a+1,a+zz,cmp3);
           // for(int i=1;i<=zz;i++) cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].z<<endl;
            for(int i=1;i<=zz-n/2;i++) u+=max(a[i].y,a[i].x);
            for(int i=zz-n/2+1;i<=n;i++) u+=a[i].maxn;
        }else{
            for(int i=1;i<=n;i++) u+=a[i].maxn;
        }
        cout<<u<<endl;
    }
    return 0;
}
