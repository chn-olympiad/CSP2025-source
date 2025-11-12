#include<bits/stdc++.h>
using namespace std;
int t,n,z;
long long ans;
struct p{
    int a,b,c,idx;
}a[100005],b[100005],c[100005];
int cnt,cno,cnk;
bool cmp(p x,p y){
    return min(x.a-x.b,x.a-x.c)>min(y.a-y.b,y.a-y.c);
}
bool cmp2(p x,p y){
    return min(x.b-x.c,x.b-x.a)>min(y.b-y.c,y.b-y.a);
}
bool cmp3(p x,p y){
    return min(x.c-x.b,x.c-x.a)>min(y.c-y.b,y.c-y.a);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        cnt=n;
        cnk=0;
        cno=0;
        for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c),a[i].idx=i;
        sort(a+1,a+cnt+1,cmp);
        while(cnt>n/2){
            if(a[cnt].b>a[cnt].c)b[++cno]=a[cnt];
            else c[++cnk]=a[cnt];
            cnt--;
        }
        while((a[cnt].a<a[cnt].b||a[cnt].a<a[cnt].c)&&cnt>0){
            if(a[cnt].b>a[cnt].c)b[++cno]=a[cnt];
            else c[++cnk]=a[cnt];
            cnt--;
        }
        if(cno>n/2){
            sort(b+1,b+cno+1,cmp2);
            while(cno>n/2){
                if(b[cno].a<b[cno].c)c[++cnk]=b[cno];
                else a[++cnt]=b[cno];
                cno--;
            }
        }
        else if(cnk>n/2){
            sort(c+1,c+cnk+1,cmp3);
            while(cnk>n/2){
                if(c[cnk].a>c[cnk].b)a[++cnt]=c[cnk];
                else b[++cno]=c[cnk];
                cnk--;
            }
        }
        ans=0;
        for(int i=1;i<=cnt;i++)ans+=a[i].a;
        for(int i=1;i<=cno;i++)ans+=b[i].b;
        for(int i=1;i<=cnk;i++)ans+=c[i].c;
        printf("%d\n",ans);
    }
}
