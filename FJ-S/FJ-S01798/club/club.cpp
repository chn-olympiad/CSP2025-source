#include<bits/stdc++.h>
#define ll long long
using namespace std;const int N=1e5+5;
ll t,n,a[N][3],g[3],b[N],c,A,d[N],di;
ll R(){ll a=0;char c=getchar();while(c<48)c=getchar();
    while(c>47)a=(a<<3)+(a<<1)+(c^48),c=getchar();return a;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=R();while(t--){n=R(),c=3,A=di=g[0]=g[1]=g[2]=0;
        for(int i=1;i<=n;i++)a[i][0]=R(),a[i][1]=R(),a[i][2]=R();
        for(int i=1;i<=n;i++){
            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])g[b[i]=0]++;
            else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])g[b[i]=1]++;
            else g[b[i]=2]++;
        }if(g[0]>n>>1)c=0;if(g[1]>n>>1)c=1;if(g[2]>n>>1)c=2;
        for(int i=1;i<=n;i++)A+=a[i][b[i]];
        if(c^3){for(int i=1;i<=n;i++)if(b[i]==c)
            d[di++]=a[i][c]-max(a[i][(c+1)%3],a[i][(c+2)%3]);
            sort(d,d+di);c=g[c]-(n>>1);for(int i=0;i<c;i++)A-=d[i];
        }
        printf("%lld\n",A);
    }
    return 0;
}/*
14:30-14:50
20min
*/