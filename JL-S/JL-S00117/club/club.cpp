#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
struct stu{
    int x,y,z;
    bool vis;
}a[N];
bool cmpx(stu x,stu y){
    if(x.x==y.x)
        return x.y+x.z<y.y+y.z;
    return x.x>y.x;
}
bool cmpy(stu x,stu y){
    if(x.y==y.y)
        return x.x+x.z<y.x+y.z;
    return x.y>y.y;
}
int totx(int ans){
    sort(a+1,a+1+n,cmpx);
    for(int i=n/2+1;i<=n;i++)
        ans+=max(a[i].y,a[i].z);
    return ans;
}
int toty(int ans){
    sort(a+1,a+1+n,cmpy);
    for(int i=n/2+1;i<=n;i++)
        ans+=max(a[i].x,a[i].z);\
    return ans;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        int x=0,y=0,z=0,xx=0,yy=0,zz=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            a[i].vis=0;
        }
        sort(a+1,a+1+n,cmpx);
        for(int i=1;i<=n/2;i++)
            x+=a[i].x;
        sort(a+1,a+1+n,cmpy);
        for(int i=1;i<=n/2;i++)
            y+=a[i].y;
        cout<<max(totx(x),toty(y))<<endl;
    }
    return 0;
}
