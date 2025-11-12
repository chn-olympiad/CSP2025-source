#include<bits/stdc++.h>
using namespace std;
int t,n;
bool b1,b2,b3;
struct people{
    int id,a,b,c;
}A[100001];
struct club{
    people p[100001];
    int Size;
}c1,c2,c3;
bool cmp_a(people x,people y){
    if(!b2&&!b3){
        return x.a-max(x.b,x.c)>y.a-max(y.b,y.c);
    }
    if(b2){
        return x.a-x.c>y.a-y.c;
    }
    if(b3){
        return x.a-x.b>y.a-y.b;
    }
}
bool cmp_b(people x,people y){
    if(!b1&&!b3){
        return x.b-max(x.a,x.c)>y.b-max(y.a,y.c);
    }
    if(b1){
        return x.b-x.c>y.b-y.c;
    }
    if(b3){
        return x.b-x.a>y.b-y.a;
    }
}
bool cmp_c(people x,people y){
    if(!b1&&!b2){
        return x.c-max(x.a,x.b)>y.c-max(y.a,y.b);
    }
    if(b1){
        return x.c-x.b>y.c-y.b;
    }
    if(b2){
        return x.c-x.a>y.c-y.a;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        c1.Size=0;
        c2.Size=0;
        c3.Size=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&A[i].a,&A[i].b,&A[i].c);
            A[i].id=i;
        }
        for(int i=1;i<=n;i++){
            if(A[i].a>=A[i].b&&A[i].a>=A[i].c){
                c1.p[++c1.Size]=A[i];
            }else if(A[i].b>=A[i].c){
                c2.p[++c2.Size]=A[i];
            }else{
                c3.p[++c3.Size]=A[i];
            }
        }
        b1=false,b2=false,b3=false;
        if(c1.Size>n/2){
            b1=true;
            sort(c1.p+1,c1.p+c1.Size+1,cmp_a);
            while(c1.Size>n/2){
                people x=c1.p[c1.Size];
                c1.Size--;
                if(x.b>=x.c){
                    c2.p[++c2.Size]=x;
                }else{
                    c3.p[++c3.Size]=x;
                }
            }
        }
        if(c2.Size>n/2){
            b2=true;
            sort(c2.p+1,c2.p+c2.Size+1,cmp_b);
            while(c2.Size>n/2){
                people x=c2.p[c2.Size];
                c2.Size--;
                if(x.a>=x.c&&b1==false){
                    c1.p[++c1.Size]=x;
                }else{
                    c3.p[++c3.Size]=x;
                }
            }
        }
        if(c3.Size>n/2){
            b3=true;
            sort(c3.p+1,c3.p+c3.Size+1,cmp_c);
            while(c3.Size>n/2){
                people x=c3.p[c3.Size];
                c3.Size--;
                if((x.a>=x.b&&!b1)||b2){
                    c1.p[++c1.Size]=x;
                }else{
                    c2.p[++c2.Size]=x;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=c1.Size;i++){
            ans+=c1.p[i].a;
        }
        for(int i=1;i<=c2.Size;i++){
            ans+=c2.p[i].b;
        }
        for(int i=1;i<=c3.Size;i++){
            ans+=c3.p[i].c;
        }
        cout<<ans<<'\n';
    }
}
