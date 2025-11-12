#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int a[100007],b[100007],c[100007],d[100007],t[100007];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n,c1=0,c2=0,c3=0;
        scanf("%d",&n);
        int ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            int xx=max(a[i],max(b[i],c[i]));
            if(a[i]==xx) t[i]=1,c1++;
            else if(b[i]==xx) t[i]=2,c2++;
            else t[i]=3,c3++;
            ans+=xx;
        }
        if(c1<=n/2 && c2<=n/2 && c3<=n/2){
            printf("%d\n",ans);
            continue;
        }
        if(c2>n/2){
            swap(c1,c2);
            for(int i=1;i<=n;i++){
                swap(a[i],b[i]);
                if(t[i]==1) t[i]=2;
                else if(t[i]==2) t[i]=1;
            }
        }
        if(c3>n/2){
            swap(c1,c3);
            for(int i=1;i<=n;i++){
                swap(a[i],c[i]);
                if(t[i]==1) t[i]=3;
                else if(t[i]==3) t[i]=1;
            }
        }
        int tot=0;
        for(int i=1;i<=n;i++){
            if(t[i]==1){
                d[++tot]=max(b[i],c[i])-a[i];
            }
        }
        sort(d+1,d+1+tot,cmp);
        for(int i=1;i<=c1-n/2;i++) ans+=d[i];
        printf("%d\n",ans);
    }
    return 0;
}