#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,sum,ma[N],b[N],len,f[N];
struct node{
    int a,b,c;
}d[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        sum=0;
        len=0;
        memset(ma,0,sizeof(ma));
        memset(f,0,sizeof(f));
        scanf("%d",&n);
        int cnta=0,cntb=0,cntc=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&d[i].a,&d[i].b,&d[i].c);
            int x=max(d[i].a,max(d[i].b,d[i].c));
            sum+=x;
            if(x==d[i].a){
                cnta++;
                f[i]=1;
                ma[i]=max(d[i].b-d[i].a,d[i].c-d[i].a);
            }else if(x==d[i].b){
                cntb++;
                f[i]=2;
                ma[i]=max(d[i].a-d[i].b,d[i].c-d[i].b);
            }else{
                cntc++;
                f[i]=3;
                ma[i]=max(d[i].a-d[i].c,d[i].b-d[i].c);
            }
        }
        if(cnta>n/2){
            for(int i=1;i<=n;i++)
                if(f[i]==1)b[++len]=ma[i];
            sort(b+1,b+len+1);
            int o=0;
            for(int i=len;i>=1;i--){
                sum+=b[i];
                o++;
                if(o==cnta-n/2)break;
            }
        }
        if(cntb>n/2){
            for(int i=1;i<=n;i++)
                if(f[i]==2)b[++len]=ma[i];
            sort(b+1,b+len+1);
            int o=0;
            for(int i=len;i>=1;i--){
                sum+=b[i];
                o++;
                if(o==cntb-n/2)break;
            }
        }
        if(cntc>n/2){
            for(int i=1;i<=n;i++)
                if(f[i]==3)b[++len]=ma[i];
            sort(b+1,b+len+1);
            int o=0;
            for(int i=len;i>=1;i--){
                sum+=b[i];
                o++;
                if(o==cntc-n/2)break;
            }
        }
        printf("%d\n",sum);
    }



    return 0;
}
