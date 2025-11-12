//Luogu: 1116515 Could you subscribe me?
#include <bits/stdc++.h>
using namespace std;
/*
土坡上狗尾巴草摇啊，摇得人眼泪掉
*/
int n,a[100005][4],belong[100005],delta[100005],cnt;
int counttt[4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=3;i++) counttt[i]=0;
        cnt=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++) scanf("%d",&a[i][j]);
            int c=a[i][1]>a[i][2]?1:2;
            c=a[i][3]>a[i][c]?3:c;
            belong[i]=c,ans+=a[i][c],counttt[c]++;
        }
        int flag=0;
        for(int i=1;i<=3;i++)
            if(counttt[i]>n/2) flag=i;
        if(flag){
            for(int i=1;i<=n;i++){
                if(belong[i]==flag){
                    delta[++cnt]=0xdfdfdfdf;
                    for(int j=1;j<=3;j++)
                        if(j!=flag) delta[cnt]=max(delta[cnt],a[i][j]-a[i][flag]);
                }
            }
            sort(delta+1,delta+cnt+1),reverse(delta+1,delta+cnt+1);
            for(int i=1;i<=counttt[flag]-n/2;i++) ans+=delta[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}