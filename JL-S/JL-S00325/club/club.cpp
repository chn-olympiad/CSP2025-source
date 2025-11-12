#include<bits/stdc++.h>
using namespace std;

int T,n;
int a[100100][5];
int t[5][100100],num[5];
int ans,de[100100];

inline void solve(){
    ans=0;int maxx;
    num[1]=num[2]=num[3]=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=3;++j)
            scanf("%d",&a[i][j]);
        maxx=max(a[i][1],max(a[i][2],a[i][3]));
        if(a[i][1]==maxx)
            t[1][++num[1]]=i;
        else if(a[i][2]==maxx)
            t[2][++num[2]]=i;
        else
            t[3][++num[3]]=i;
        ans+=maxx;
    }
    int x=-1;
    for(int i=1;i<=3;++i)
        if(num[i]>n/2) x=i;
    if(x==-1) printf("%d\n",ans);
    else{
        for(int i=1;i<=num[x];++i){
            de[i]=0x3f3f3f3f;
            for(int j=1;j<=3;++j)
                if(j!=x)
                    de[i]=min(de[i],abs(a[t[x][i]][j]-a[t[x][i]][x]));
        }
        sort(de+1,de+num[x]+1);
        for(int i=1;i+n/2<=num[x];++i){
            ans-=de[i];
        }
        printf("%d\n",ans);
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}
