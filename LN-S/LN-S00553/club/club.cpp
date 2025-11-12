#include <bits/stdc++.h>
using namespace std;
const int mxn=1e5+5;
long long n,t,num;
struct node{
    long long r,a,b,c;
}g[mxn],s;
bool cmp(node g1_,node g2_){
    int mx1=max(g1_.a,max(g1_.b,g1_.c));
    int mx2=max(g2_.a,max(g2_.b,g2_.c));
    return mx1>mx2;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t>0){
        t--;
        num=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            int f=max(x,max(y,z)),mi;
            int f1,f2,f3;
            if(x==f) mi=max(y,z);
            else if(y==f) mi=max(x,z);
            else mi=max(x,y);
            g[i].r=mi,g[i].a=x-mi,g[i].b=y-mi,g[i].c=z-mi;
        }
        stable_sort(g+1,g+n+1,cmp);
        int flag=1;
        for(int i=1;i<=n;i++){
            if(g[i].c!=0 || g[i].b!=0){
                flag=0;
                break;
            }
        }
        if(flag==1){
            for(int i=1;i<=n/2;i++){
                num+=g[i].a;
            }
            cout<<num;
        }
        else{
            s.a=n/2,s.b=n/2,s.c=n/2;
            for(int i=1;i<=n;i++){
                int f=max(g[i].a,max(g[i].b,g[i].c)),qn,qm,f1,f2,f3;
                if(f==0) continue;
                if(g[i].a==f) f1=1;
                else if(g[i].b==f) f1=2;
                else f1=3;
                if(f1==1){
                    f=max(g[i].b,g[i].c);
                    if(g[i].b==f) f2=2,f3=3;
                    else f2=3,f3=2;
                }
                else if(f1==2){
                    f=max(g[i].a,g[i].c);
                    if(g[i].a==f) f2=1,f3=3;
                    else f2=3,f3=1;
                }
                else if(f1==3){
                    f=max(g[i].a,g[i].b);
                    if(g[i].a==f) f2=1,f3=2;
                    else f2=2,f3=1;
                }
                if(f1==1){
                    if(s.a!=0) num+=g[i].r+g[i].a,s.a--;
                    else{
                        if(f2==2){
                            if(s.b!=0) num+=g[i].r+g[i].b,s.b--;
                            else num+=g[i].r+g[i].c,s.c--;
                        }
                        else{
                            if(s.c!=0) num+=g[i].r+g[i].c,s.c--;
                            else num+=g[i].r+g[i].b,s.b--;
                        }
                    }
                }
                else if(f1==2){
                    if(s.b!=0) num+=g[i].r+g[i].b,s.b--;
                    else{
                        if(f2==1){
                            if(s.a!=0) num+=g[i].r+g[i].a,s.a--;
                            else num+=g[i].r+g[i].c,s.c--;
                        }
                        else{
                            if(s.c!=0) num+=g[i].r+g[i].c,s.c--;
                            else num+=g[i].r+g[i].a,s.a--;
                        }
                    }
                }
                else if(f1==3){
                    if(s.c!=0) num+=g[i].r+g[i].c,s.c--;
                    else{
                        if(f2==1){
                            if(s.a!=0) num+=g[i].r+g[i].a,s.a--;
                            else num+=g[i].r+g[i].b,s.b--;
                        }
                        else{
                            if(s.b!=0) num+=g[i].r+g[i].b,s.b--;
                            else num+=g[i].r+g[i].a,s.a--;
                        }
                    }
                }
            }
            cout<<num<<endl;
        }
    }
    return 0;
}
