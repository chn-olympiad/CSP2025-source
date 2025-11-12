#include<bits/stdc++.h>
using namespace std;
struct member{
    int a,b,c;
    int d,e,f;
}awa[100009];
bool cmp(member x,member y){
    return x.d>y.d;
}
bool cmp1(member x,member y){
    return x.e>y.e;
}
bool cmp2(member x,member y){
    return x.f>y.f;
}
int main(){
   // freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    int t,ans;
    scanf("%d",&t);int n,i,s1,s2,s3;
    while(t--){
        scanf("%d",&n);
        s1=s2=s3=ans=0;
        for(i = 1;i<=n;++i){
            cin>>awa[i].a>>awa[i].b>>awa[i].c;
            awa[i].d=awa[i].a-awa[i].b+awa[i].a-awa[i].c;
            awa[i].e=awa[i].b-awa[i].a+awa[i].b-awa[i].c;
            awa[i].f=awa[i].c-awa[i].b+awa[i].c-awa[i].a;
        }
        if(n%3!=0)
        for(i = 1;i<=n/3+1;++i){
            if(s1+1>=n/2&&s3+1>=n/2){
                sort(awa+1,awa+n+1,cmp1);
            ans+=awa[1].b;
            awa[1].d=awa[1].f=awa[1].e=0;++s2;
            }
            else if(s2+1>=n/2&&s3+1>=n/2){
                sort(awa+1,awa+n+1,cmp);
            ans+=awa[1].a;
            awa[1].e=awa[1].f=awa[1].d=0;++s1;
            }
            else if(s1+1>=n/2&&s2+1>=n/2){
            sort(awa+1,awa+n+1,cmp2);
            ans+=awa[1].c;
            awa[1].e=awa[1].d=awa[1].f=0;++s3;
            }
            else if(s1+1>=n/2){
                sort(awa+1,awa+n+1,cmp1);
            ans+=awa[1].b;
            awa[1].d=awa[1].f=awa[1].e=0;
            sort(awa+1,awa+n+1,cmp2);
            ans+=awa[1].c;
            awa[1].e=awa[1].d=awa[1].f=0;++s2;++s3;
            }
            else if(s2+1>=n/2){
                sort(awa+1,awa+n+1,cmp);
            ans+=awa[1].a;
            awa[1].e=awa[1].f=awa[1].d=0;
            sort(awa+1,awa+n+1,cmp2);
            ans+=awa[1].c;
            awa[1].e=awa[1].d=awa[1].f=0;++s3;++s1;
            }
            else if(s3+1>=n/2){
                sort(awa+1,awa+n+1,cmp);
            ans+=awa[1].a;
            awa[1].e=awa[1].f=awa[1].d=0;
            sort(awa+1,awa+n+1,cmp1);
            ans+=awa[1].b;
            awa[1].d=awa[1].f=awa[1].e=0;++s1;++s2;
            }
            else if(s1+1<n/2&&s2+1<n/2&&s3+1<=n/2){
                sort(awa+1,awa+n+1,cmp);
            ans+=awa[1].a;
            awa[1].e=awa[1].f=awa[1].d=0;
            sort(awa+1,awa+n+1,cmp1);
            ans+=awa[1].b;
            awa[1].d=awa[1].f=awa[1].e=0;
            sort(awa+1,awa+n+1,cmp2);
            ans+=awa[1].c;
            awa[1].e=awa[1].d=awa[i].f=0;++s1;++s2;++s3;
            }
        else break;
    }
    else
        for(i = 1;i<=n/3+1;++i){
            if(s1+1>=n/2&&s3+1>=n/2){
                sort(awa+1,awa+n+1,cmp1);
            ans+=awa[1].b;
            awa[1].d=awa[1].f=awa[1].e=0;++s2;
            }
            else if(s2+1>=n/2&&s3+1>=n/2){
                sort(awa+1,awa+n+1,cmp);
            ans+=awa[1].a;
            awa[1].e=awa[1].f=awa[1].d=0;++s1;
            }
            else if(s1+1>=n/2&&s2+1>=n/2){
            sort(awa+1,awa+n+1,cmp2);
            ans+=awa[1].c;
            awa[1].e=awa[1].d=awa[1].f=0;++s3;
            }
            else if(s1+1>=n/2){
                sort(awa+1,awa+n+1,cmp1);
            ans+=awa[1].b;
            awa[1].d=awa[1].f=awa[1].e=0;
            sort(awa+1,awa+n+1,cmp2);
            ans+=awa[1].c;
            awa[1].e=awa[1].d=awa[1].f=0;++s2;++s3;
            }
            else if(s2+1>=n/2){
                sort(awa+1,awa+n+1,cmp);
            ans+=awa[1].a;
            awa[1].e=awa[1].f=awa[1].d=0;
            sort(awa+1,awa+n+1,cmp2);
            ans+=awa[1].c;
            awa[1].e=awa[1].d=awa[i].f=0;++s1;++s3;
            }
            else if(s3+1>=n/2){
                sort(awa+1,awa+n+1,cmp);
            ans+=awa[1].a;
            awa[1].e=awa[1].f=awa[1].d=0;
            sort(awa+1,awa+n+1,cmp1);
            ans+=awa[1].b;
            awa[1].d=awa[1].f=awa[1].e=0;++s2;++s3;
            }
            else if(s1+1<n/2&&s2+1<n/2&&s3+1<n/2){
                sort(awa+1,awa+n+1,cmp);
            ans+=awa[1].a;
            awa[1].e=awa[1].f=awa[1].d=0;
            sort(awa+1,awa+n+1,cmp1);
            ans+=awa[1].b;
            awa[1].d=awa[1].f=awa[1].e=0;
            sort(awa+1,awa+n+1,cmp2);
            ans+=awa[1].c;
            awa[1].e=awa[1].d=awa[1].f=0;++s1;++s2;++s3;
            }
            else break;
        }
    printf("\n%d",ans);
    }
    return 0;
}
