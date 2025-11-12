#include<bits/stdc++.h>
using namespace std;
int t,n,ans,ac=0,bc=0,cc=0;
struct people{
    int a,b,c;
};
int funa(people a,people b){
    return a.a>b.a;
}
int funb(people a,people b){
    return a.b>b.b;
}
int func(people a,people b){
    return a.c>b.c;
}
const int MAXx=1e5;
people p[MAXx];
int paia(){
        sort(p,p+n,funa);
        for(int i=0;i<n;i++){
            if(ac==n/2){
                p[i].a=0;
            }
            if(p[i].a>p[i].b && p[i].a>p[i].c && ac<n/2){
                ans+=p[i].a;
                p[i].a=0;
                p[i].b=0;
                p[i].c=0;
                ac++;
            }
        }
        sort(p,p+n,funb);
        for(int i=0;i<n;i++){
            if(bc==n/2){
                p[i].b=0;
            }
            if(p[i].b>p[i].a && p[i].b>p[i].c && bc<n/2){
                ans+=p[i].b;
                p[i].a=0;
                p[i].b=0;
                p[i].c=0;
                bc++;
            }
        }
        sort(p,p+n,func);
        for(int i=0;i<n;i++){
            if(cc==n/2){
                p[i].c=0;
            }
            if(p[i].c>p[i].b && p[i].c>p[i].a && cc<n/2){
                ans+=p[i].c;
                p[i].a=0;
                p[i].b=0;
                p[i].c=0;
                cc++;
            }
        }

    return ans;
}
int paib(){
    sort(p,p+n,funb);
        for(int i=0;i<n;i++){
            if(bc==n/2){
                p[i].b=0;
            }
            if(p[i].b>p[i].a && p[i].b>p[i].c && bc<n/2){
                ans+=p[i].b;
                p[i].a=0;
                p[i].b=0;
                p[i].c=0;
                bc++;
            }
        }
    sort(p,p+n,funa);
        for(int i=0;i<n;i++){
            if(ac==n/2){
                p[i].a=0;
            }
            if(p[i].a>p[i].b && p[i].a>p[i].c && ac<n/2){
                ans+=p[i].a;
                p[i].a=0;
                p[i].b=0;
                p[i].c=0;
                ac++;
            }
        }
    sort(p,p+n,func);
        for(int i=0;i<n;i++){
            if(cc==n/2){
                p[i].c=0;
            }
            if(p[i].c>p[i].b && p[i].c>p[i].a && cc<n/2){
                ans+=p[i].c;
                p[i].a=0;
                p[i].b=0;
                p[i].c=0;
                cc++;
            }
        }

    return ans;
}
int paic(){
    sort(p,p+n,func);
    for(int i=0;i<n;i++){
            if(cc==n/2){
                p[i].c=0;
            }
            if(p[i].c>p[i].b && p[i].c>p[i].a && cc<n/2){
                ans+=p[i].c;
                p[i].a=0;
                p[i].b=0;
                p[i].c=0;
                cc++;
            }
        }
    sort(p,p+n,funa);
    for(int i=0;i<n;i++){
            if(ac==n/2){
                p[i].a=0;
            }
            if(p[i].a>p[i].b && p[i].a>p[i].c && ac<n/2){
                ans+=p[i].a;
                p[i].a=0;
                p[i].b=0;
                p[i].c=0;
                ac++;
            }
        }
    sort(p,p+n,funb);
        for(int i=0;i<n;i++){
            if(bc==n/2){
                p[i].b=0;
            }
            if(p[i].b>p[i].a && p[i].b>p[i].c && bc<n/2){
                ans+=p[i].b;
                p[i].a=0;
                p[i].b=0;
                p[i].c=0;
                bc++;
            }
        }


    return ans;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        ans=0,ac=0,bc=0,cc=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>p[i].a>>p[i].b>>p[i].c;
        }
        int aans=paia(),bans=paib(),cans=paic();
        if(aans>bans && aans>cans){
            ans=aans;
        }
        if(bans>aans && bans>cans){
            ans=bans;
        }
        if(cans>bans && cans>aans){
            ans=cans;
        }
        cout<<ans<<endl;
    }
    return 0;
}
