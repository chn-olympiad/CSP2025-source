#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=100005;
int T, n, x[N], tx=0, y[N], ty=0, z[N], tz=0, d[N], ans=0;
bool cmp(int a, int b){
    return d[a]>d[b];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        tx=ty=tz=ans=0;
        for(int i=1;i<=n;i++){
            int a, b, c;
            scanf("%d%d%d",&a,&b,&c);
            if(a>=b&&a>=c) x[++tx]=i, ans+=a, d[i]=a-max(b,c);
            else if(b>=a&&b>=c) y[++ty]=i, ans+=b, d[i]=b-max(a,c);
            else if(c>=a&&c>=b) z[++tz]=i, ans+=c, d[i]=c-max(a,b);
        }
        if(tx>n/2){
            sort(x+1,x+tx+1,cmp);
            for(int i=n/2+1;i<=tx;i++) ans-=d[x[i]];
        }
        if(ty>n/2){
            sort(y+1,y+ty+1,cmp);
            for(int i=n/2+1;i<=ty;i++) ans-=d[y[i]];
        }
        if(tz>n/2){
            sort(z+1,z+tz+1,cmp);
            for(int i=n/2+1;i<=tz;i++) ans-=d[z[i]];
        }
        printf("%d\n",ans);
    }
    return 0;
}