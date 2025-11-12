#include <bits/stdc++.h>
using namespace std;
struct club{
    int xb;
    int like;
}a[100005],b[100005],c[100005];
struct cha1{
    int xb,ch;
}cha[100005];
bool cmp(cha1 num1,cha1 num2){
    if(num1.ch>num2.ch) return 1;
    else if(num1.ch==num2.ch) return num1.xb<num2.xb;
    return 0;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long int ans=0;
    long long int t,n;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].like,&b[i].like,&c[i].like);
            if(a[i].like>=b[i].like&&b[i].like>=c[i].like)cha[i].ch=a[i].like-b[i].like-c[i].like;
            if(a[i].like>=c[i].like&&c[i].like>=b[i].like)cha[i].ch=a[i].like-c[i].like-b[i].like;
            if(b[i].like>=a[i].like&&a[i].like>=c[i].like)cha[i].ch=b[i].like-a[i].like-c[i].like;
            if(b[i].like>=c[i].like&&c[i].like>=a[i].like)cha[i].ch=b[i].like-c[i].like-a[i].like;
            if(c[i].like>=a[i].like&&a[i].like>=b[i].like)cha[i].ch=c[i].like-a[i].like-b[i].like;
            if(c[i].like>=b[i].like&&b[i].like>=a[i].like)cha[i].ch=b[i].like-b[i].like-a[i].like;
            cha[i].xb=i;
        }
        sort(cha+1,cha+n+1,cmp);
       /* for(int i=1;i<=n;i++){
            cout<<cha[i].xb;
        }*/
        //cout<<endl;
        int maxa=n/2,maxb=n/2,maxc=n/2;
        for(int i=1;i<=n;i++){
                int j=cha[i].xb;
            if(a[j].like>b[j].like&&a[j].like>c[j].like){
                if(maxa>0) {maxa--;ans+=a[j].like;}
                else ans+=max(b[j].like,c[j].like);
            }
            if(b[j].like>a[j].like&&b[j].like>c[j].like){
                if(maxb>0) {maxb--;ans+=b[j].like;}
                else ans+=max(a[j].like,c[j].like);
            }
            if(c[j].like>b[j].like&&c[j].like>a[j].like){
                if(maxc>0) {maxc--;ans+=c[j].like;}
                else ans+=max(b[j].like,a[j].like);
            }
        }
        printf("%lld\n",ans);
        ans=0;
    }
    return 0;
}
