#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
bool ok(int a[],int b[],int c[]){
    for(int i=1;i<=100;i++) if(b[i]==0&&c[i]==0); else return 0;
    return 1;

}
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int T;
	;scanf("%d",&T);
	;while(T--){
        int n;
        scanf("%d",&n);
        if(n==2){int a[3],b[3],mx=-1;;
            for(int i=1;i<=3;i++) scanf("%d",&a[i]);
            for(int i=1;i<=3;i++) scanf("%d",&b[i]);
            for(int i=1;i<=3;i++)
                for(int j=1;j<=3;j++){if(i==j)continue;
                    mx=max(a[i]+b[j],mx);}
            printf("%d\n",mx);
        }
        else if(n==4){
            int a[4],b[4],c[4],d[4],mx=-1;
            for(int i=1;i<=3;i++) scanf("%d",&a[i]);
            for(int i=1;i<=3;i++) scanf("%d",&b[i]);
            for(int i=1;i<=3;i++) scanf("%d",&c[i]);
            for(int i=1;i<=3;i++) scanf("%d",&d[i]);
            for(int i=1;i<=3;i++){
               for(int i=1;i<=3;i++){
                    for(int j=1;j<=3;j++){
                        for(int k=1;k<=3;k++){
                            if(i==j&&j==k)continue;
                            for(int l=1;l<=3;l++){
                                if((i==j&&i==l)||(i==k&&i==l)||(j==k&&j==l)) continue;
                                mx=max(a[i]+b[j]+c[k]+d[l],mx);
                            }
                        }
                    }
               }
            }
            printf("%d\n",mx);
        }

        else{
            int a[maxn],b[maxn],c[maxn],ans=0;
            for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
            if(ok(a,b,c)){
                sort(a+1,a+1+n);
                for(int i=1;i<=n/2;i++) ans+=a[i];
                printf("%d",ans);continue;
            }
            else{
            for(int i=1;i<=n;i++)
                ans+=max(a[i],max(b[i],c[i]));
            printf("%d\n",ans); continue;
            }
        }
	}
	return 0;
}
