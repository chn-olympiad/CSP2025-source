#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5,INF=2e9;
int T,ca[3];
struct pe {
    int a[3];
} a[3][MAXN];
int maxt(pe t) {
    if(t.a[0]>t.a[1]&&t.a[0]>t.a[2]) return 0;
    else if(t.a[1]>t.a[2]) return 1;
    else return 2;
}
bool cmp(pe x,pe y) {
    int i,j=maxt(x),t,mx,my;
    if(j==0) i=1;
    else i=0;
    t=3-j-i;
    mx=min(x.a[j]-x.a[i],x.a[j]-x.a[t]);
    my=min(y.a[j]-y.a[i],x.a[j]-x.a[t]);
    return mx>my;
}
int club(int n) {
    int ans=0;
    int i,j;
    for(int k=0;k<3;k++) if(ca[k]>n/2) j=k;
    sort(a[j],a[j]+ca[j],cmp);
    if(j==0) i=1;
    else i=0;
    int t=3-j-i;
    while(ca[j]>n/2) {
        if(a[j][ca[j]-1].a[i]>a[j][ca[j]-1].a[t]) a[i][ca[i]++]=a[j][--ca[j]];
        else a[t][ca[t]++]=a[j][--ca[j]];
    }
    for(int i=0;i<3;i++) {
        for(int j=0;j<ca[i];j++) ans+=a[i][j].a[i];
    }
    return ans;
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for(int i=0;i<T;i++) {
        int n;ca[0]=0;ca[1]=0;ca[2]=0;
        cin>>n;
        for(int j=0;j<n;j++) {
            pe t;
            cin>>t.a[0]>>t.a[1]>>t.a[2];
            int mt=maxt(t);
            a[mt][ca[mt]++]=t;
        }
        int ans=club(n);
        cout<<ans<<endl;
    }
    return 0;
}
