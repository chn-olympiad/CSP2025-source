#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int T,n,a[N][5],ans,tmp[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x,y,z,mx;
            scanf("%d%d%d",&x,&y,&z);
            mx=max(x,max(y,z));
            a[i][1]=mx-x;
            a[i][2]=mx-y;
            a[i][3]=mx-z;
            ans+=mx;
        }
        //printf("%d\n",ans);
        for(int i=1;i<=3;i++){
            int cnt0=0;
            for(int j=1;j<=n;j++)
                if(a[j][i]==0)
                    tmp[++cnt0]=min(a[j][i%3+1],a[j][(i+1)%3+1]);
            if(cnt0>n/2){
                sort(tmp+1,tmp+cnt0+1);
                int anss=0;
                for(int j=1;j<=cnt0-n/2;j++)anss+=tmp[j];
                ans-=anss;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
//Stanford REA rp++