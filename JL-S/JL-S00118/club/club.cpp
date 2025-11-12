#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
struct str {
    int x,y,z;
}a[N];
int ans1,ans2,ans3;
bool cmp_x(str a, str b) {
    return a.x>b.x;
}
bool cmp_y(str a, str b) {
    return a.y>b.y;
}
bool cmp_z(str a, str b) {
    return a.z>b.z;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--) {
        ans1=ans2=ans3=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i].x >>a[i].y >>a[i].z;
        sort(a+1,a+n+1,cmp_x);
        for(int i=1;i<=n/2;i++) ans1+=a[i].x;
        for(int i=n/2+1;i<=n;i++) ans1+=max(a[i].y, a[i].z);
        sort(a+1,a+n+1,cmp_y);
        for(int i=1;i<=n/2;i++) ans2+=a[i].y;
        for(int i=n/2+1;i<=n;i++) ans2+=max(a[i].x, a[i].z);
        sort(a+1,a+n+1,cmp_z);
        for(int i=1;i<=n/2;i++) ans3+=a[i].z;
        for(int i=n/2+1;i<=n;i++) ans3+=max(a[i].x, a[i].y);
        cout<<max(ans1,max(ans2,ans3))<<endl;
    }
    return 0;
}
