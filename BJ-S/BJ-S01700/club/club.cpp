#include<bits/stdc++.h>
using namespace std;
struct bx{
    long long x=0,y=0;
};
struct ax{
    bx a,b,c;
    long long d=0;
};
struct js{
    bx a,b,c;
};
bool cmp(ax a,ax b){
    return a.d>b.d;
}
int k,T;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        vector<ax> d1;
        vector<ax> d2;
        vector<ax> d3;
        long long n,m;
        ax a[10005];
        js cnt;
        cin>>n;
        int u=n/2;
        for(int i=1;i<=n;i++){
            ax x1;
            cin>>a[i].a.x>>a[i].b.x>>a[i].c.x;
            a[i].a.y=1;
            a[i].b.y=2;
            a[i].c.y=3;
            if(a[i].a.x>a[i].b.x){
                if(a[i].a.x>a[i].c.x){
                    x1.a.x=a[i].a.x;
                    x1.a.y=a[i].a.y;
                    if(a[i].b.x>a[i].c.x){
                        x1.b.x=a[i].b.x;
                        x1.b.y=a[i].b.y;
                        x1.c.x=a[i].c.x;
                        x1.c.y=a[i].c.y;
                    }else{
                        x1.b.x=a[i].c.x;
                        x1.b.y=a[i].c.y;
                        x1.c.x=a[i].b.x;
                        x1.c.y=a[i].b.y;
                    }
                }else{
                    x1.a.x=a[i].c.x;
                    x1.a.y=a[i].c.y;
                    x1.b.x=a[i].a.x;
                    x1.b.y=a[i].a.y;
                    x1.c.x=a[i].b.x;
                    x1.c.y=a[i].b.y;
                }
            }else{
                if(a[i].b.x>a[i].c.x){
                    x1.a.x=a[i].b.x;
                    x1.a.y=a[i].b.y;
                    if(a[i].a.x>a[i].c.x){
                        x1.b.x=a[i].a.x;
                        x1.b.y=a[i].a.y;
                        x1.c.x=a[i].c.x;
                        x1.c.y=a[i].c.y;
                    }else{
                        x1.b.x=a[i].c.x;
                        x1.b.y=a[i].c.y;
                        x1.c.x=a[i].a.x;
                        x1.c.y=a[i].a.y;
                    }
                }else{
                    x1.a.x=a[i].c.x;
                    x1.a.y=a[i].c.y;
                    x1.b.x=a[i].b.x;
                    x1.b.y=a[i].b.y;
                    x1.c.x=a[i].a.x;
                    x1.c.y=a[i].a.y;
                }
            }
            a[i].a.x=x1.a.x;
            a[i].a.y=x1.a.y;
            a[i].b.x=x1.b.x;
            a[i].b.y=x1.b.y;
            a[i].c.x=x1.c.x;
            a[i].c.y=x1.c.y;
            a[i].d=a[i].a.x-a[i].b.x;
            //cout<<a[i].a.x<<' '<<a[i].a.y<<' '<<a[i].b.x<<' '<<a[i].b.y<<' '<<a[i].c.x<<' '<<a[i].c.y<<' '<<a[i].d<<"\n";
        }
        for(int i=1;i<=n;i++){
            if(a[i].a.y==1){
                d1.push_back(a[i]);
                cnt.a.x+=a[i].a.x;
                cnt.a.y++;
            }else if(a[i].a.y==2){
                d2.push_back(a[i]);
                cnt.b.x+=a[i].a.x;
                cnt.b.y++;
            }else{
                d3.push_back(a[i]);
                cnt.c.x+=a[i].a.x;
                cnt.c.y++;
            }
        }
        long long ans=cnt.a.x+cnt.b.x+cnt.c.x;
        if(cnt.a.y>u){
            sort(d1.begin(),d1.end(),cmp);
            for(int i=int(d1.size())-1;i>=u;i--){
                ans-=d1[i].d;
            }
        }
        if(cnt.b.y>u){
            sort(d2.begin(),d2.end(),cmp);
            for(int i=int(d2.size())-1;i>=u;i--){
                ans-=d2[i].d;
            }
        }
        if(cnt.c.y>u){
            sort(d3.begin(),d3.end(),cmp);
            for(int i=int(d3.size())-1;i>=u;i--){
                ans-=d3[i].d;
            }
        }
        cout<<ans<<"\n";
        //cout<<"\n"<<cnt.a.x<<' '<<cnt.a.y<<' '<<cnt.b.x<<' '<<cnt.b.y<<' '<<cnt.c.x<<' '<<cnt.c.y<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
