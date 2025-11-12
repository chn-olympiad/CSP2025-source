#include <bits/stdc++.h>
using namespace std;
namespace Light_Tea{
    void Main();
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    Light_Tea::Main();
    return 0;
}
namespace Light_Tea{
    #define i64 long long

    constexpr int kN=1e5+5;
    int n,a[kN][5],buf[5][kN],top[5];

    void Proc(){
        scanf("%d",&n);
        
        top[1]=top[2]=top[3]=0;
        int ans=0;

        for(int i=1; i<=n; i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            ans+=max(max(a[i][1],a[i][2]),a[i][3]);
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
                buf[1][++top[1]]=a[i][1]-max(a[i][2],a[i][3]);
            }else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
                buf[2][++top[2]]=a[i][2]-max(a[i][1],a[i][3]);
            }else{
                buf[3][++top[3]]=a[i][3]-max(a[i][1],a[i][2]);
            }
        }

        if(max(max(top[1],top[2]),top[3])<=(n>>1)){
            printf("%d\n",ans);
        }else{
            int d;
            if(top[1]>(n>>1)) d=1;
            else if(top[2]>(n>>1)) d=2;
            else d=3;

            sort(buf[d]+1,buf[d]+top[d]+1);
            for(int i=1; i<=(top[d]-(n>>1)); i++) ans-=buf[d][i];

            printf("%d\n",ans);
        }
    }

    void Main(){
        int T;
        scanf("%d",&T);
        while(T--) Proc();
    }
}