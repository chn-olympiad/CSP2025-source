#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int d[100005][4],m[100005][4],as[100005],x1,x2,x3,ans;
void calc(int a,int b,int c,int j){
    if(a>b&&a>c){
        ans+=a;
        x1++;
        m[j][0]=a-(b>c?b:c);
        m[j][1]=1;
        return;
    }
    if(b>a&&b>c){
        ans+=b;
        x2++;
        m[j][0]=b-(a>c?a:c);
        m[j][2]=1;
        return;
    }
    if(c>a&&c>b){
        ans+=c;
        x3++;
        m[j][0]=c-(a>b?a:b);
        m[j][3]=1;
        return;
    }
    ans+=max(a,max(b,c));
    m[j][0]=100000007;
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        memset(d,0,sizeof(d));
        memset(m,0,sizeof(m));
        memset(as,0,sizeof(as));
        x1=0;x2=0;x3=0;ans=0;int tot=0;
        scanf("%d",&n);
        for(int j=1;j<=n;j++){
            scanf("%d%d%d",&d[j][1],&d[j][2],&d[j][3]);
            calc(d[j][1],d[j][2],d[j][3],j);
        }
        if(x1<=n/2&&x2<=n/2&&x3<=n/2){
            printf("%d\n",ans);
            continue;
        }
        int l=max(x1,max(x2,x3))-n/2;
        int rt=max(x1,max(x2,x3));
        int num;
        if(x1==rt)num=1;
        if(x2==rt)num=2;
        if(x3==rt)num=3;
        for(int j=1;j<=n;j++)if(m[j][num]==1)as[++tot]=m[j][0];
        sort(as+1,as+tot+1);
        for(int i=1;i<=l;i++)ans-=as[i];
        printf("%d\n",ans);
    }
    return 0;
}
