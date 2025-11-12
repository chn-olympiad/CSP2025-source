#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z;
};
node a[100010];
bool cmp1(node c,node d){
    return c.x>d.x;
}
bool cmp2(node c,node d){
    return c.y>d.y;
}
bool cmp3(node c,node d){
    return c.z>d.z;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        int cntx=0,cnty=0,cntz=0,rx=0,ry=0,rz=0;
        sort(a+1,a+n+1,cmp1);
        for(int i=1;i<=n;i++){
            if(a[i].x>a[i].y&&a[i].x>a[i].z&&rx<n/2){
                cntx+=a[i].x;
                rx++;
            }else if(a[i].y>a[i].x&&a[i].y>a[i].z&&ry<n/2){
                cntx+=a[i].y;
                ry++;
            }else if(rz<n/2){
                cntx+=a[i].z;
                rz++;
            }else if(a[i].x>a[i].y&&rx<n/2){
                cntx+=a[i].x;
                rx++;
            }else if(ry<n/2){
                cntx+=a[i].y;
                ry++;
            }else {
                cntx+=a[i].x;
                rx++;
            }
        }
        sort(a+1,a+n+1,cmp2);
        rx=0,ry=0,rz=0;
        for(int i=1;i<=n;i++){
            if(a[i].y>a[i].x&&a[i].y>a[i].z&&ry<n/2){
                cnty+=a[i].y;
                ry++;
            }else if(a[i].x>a[i].y&&a[i].x>a[i].z&&rx<n/2){
                cnty+=a[i].x;
                rx++;
            }else if(rz<n/2){
                cnty+=a[i].z;
                rz++;
            }else if(a[i].y>a[i].x&&ry<n/2){
                cnty+=a[i].y;
                ry++;
            }else if(rx<n/2){
                cnty+=a[i].x;
                rx++;
            }else {
                cnty+=a[i].y;
                ry++;
            }
        }
        sort(a+1,a+n+1,cmp3);
        rx=0,ry=0,rz=0;
        for(int i=1;i<=n;i++){
            if(a[i].z>a[i].x&&a[i].z>a[i].y&&rz<n/2){
                cntz+=a[i].z;
                rz++;
            }else if(a[i].x>a[i].y&&a[i].x>a[i].z&&rx<n/2){
                cntz+=a[i].x;
                rx++;
            }else if(ry<n/2){
                cntz+=a[i].y;
                ry++;
            }else if(a[i].z>a[i].x&&rz<n/2){
                cntz+=a[i].z;
                rz++;
            }else if(rx<n/2){
                cntz+=a[i].x;
                rx++;
            }else {
                cntz+=a[i].z;
                rz++;
            }
        }
        cout<<max(cntx,max(cnty,cntz))<<endl;
    }
    return 0;
}
