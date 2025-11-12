#include<bits/stdc++.h>
using namespace std;
long long t,ans,n,a[1010101][5],mi[1010101][5][5],cnt1,cnt2,cnt3;
struct stu{
    long long bel,c1,c2,c3;
}s[10101011];
bool cmp(stu x,stu y){
    return x.c1>y.c1;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        
            for(int i=1;i<=n;i++){
                for(int j=1;j<=3;j++){
                scanf("%lld",&a[i][j]);
                c1=a[i][1];
                c2=a[i][2];
                c3=a[i][3];
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=3;i++){
                for(int j=1;j<3;j++){
                    mi[k][i][j]=a[k][i]-a[k][j];
                }
            }
        }
        if(n<=200){
            for(int i=1;i<=n;i++){
                int maxn=max(a[i][1],max(a[i][2],a[i][3]));
                if(a[i][1]==maxn){
                    s[i].bel=1;
                    ans+=maxn;
                    cnt1++;
                }
                else if(a[i][2]==maxn){
                    s[i].bel=2;
                    ans+=maxn;
                    cnt2++;
                }
                else if(a[i][3]==maxn){
                    s[i].bel=3;
                    ans+=maxn;
                    cnt3++;
                }
            }
        }else{
            sort(s+1,s+1+n,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=s[i].c1;
            }
        }
        printf("%lld\n",ans);
    }
        
    fclose(stdin);
    fclose(stdout);

    return 0;
}
