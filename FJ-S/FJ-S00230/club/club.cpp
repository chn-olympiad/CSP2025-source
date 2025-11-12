#include<bits/stdc++.h>
using namespace std;

int n,c[4],a[100010][4];
inline void Main(){
    for(int i=1;i<=3;++i)c[i]=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=3;++j)scanf("%d",&a[i][j]);
        if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])++c[1];
        if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])++c[2];
        if(a[i][3]>a[i][1]&&a[i][3]>a[i][2])++c[3];
    }
    int ans=0;
    for(int i=1;i<=n;++i)ans+=max({a[i][1],a[i][2],a[i][3]});
    vector<int>V;
    if(c[1]>c[2]&&c[1]>c[3]){
        if(c[1]<=n/2){ printf("%d\n",ans); return; }
        for(int i=1;i<=n;++i)
            if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])
                V.push_back(a[i][1]-max(a[i][2],a[i][3]));
        sort(V.begin(),V.end());
        for(int i=0;i<c[1]-n/2;++i)ans-=V[i];
        printf("%d\n",ans);
    }
    if(c[2]>c[1]&&c[2]>c[3]){
        if(c[2]<=n/2){ printf("%d\n",ans); return; }
        for(int i=1;i<=n;++i)
            if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])
                V.push_back(a[i][2]-max(a[i][1],a[i][3]));
        sort(V.begin(),V.end());
        for(int i=0;i<c[2]-n/2;++i)ans-=V[i];
        printf("%d\n",ans);
    }
    if(c[3]>c[1]&&c[3]>c[2]){
        if(c[3]<=n/2){ printf("%d\n",ans); return; }
        for(int i=1;i<=n;++i)
            if(a[i][3]>a[i][1]&&a[i][3]>a[i][2])
                V.push_back(a[i][3]-max(a[i][1],a[i][2]));
        sort(V.begin(),V.end());
        for(int i=0;i<c[3]-n/2;++i)ans-=V[i];
        printf("%d\n",ans);
    }
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T; scanf("%d",&T); while(T--)Main();
}