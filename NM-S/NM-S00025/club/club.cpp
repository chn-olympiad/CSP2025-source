#include<bits/stdc++.h>
using namespace std;

struct ren{
    int a,b,c;
};
ren r[100010],rr[100010];
int rn;
bool cmpa(ren x,ren y){
    return x.a>y.a;
}
bool cmpb(ren x,ren y){
    return x.b>y.b;
}
bool cmpc(ren x,ren y){
    return x.c>y.c;
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;scanf("%d", &t);
    while(t--){
        int n;scanf("%d", &n);
        long long x=0,y=0,z=0,xx=0,yy=0,zz=0;
        rn=0;
        for(int i=0;i<n;i++){
            scanf("%d %d %d", &r[i].a, &r[i].b, &r[i].c);
        }
        sort(r,r+n,cmpa);
        for(int i=0;i<n;i++){
            if(r[i].a==-1) continue;
            if(r[i].a==max( max(r[i].a,r[i].b), r[i].c)){
                if(xx<(n/2)){
                    x+=r[i].a;
                    xx++;
                    r[i].a=-1,r[i].b=-1,r[i].c=-1;

                }
                else break;
            }
        }
        sort(r,r+n,cmpb);
        for(int i=0;i<n;i++){
            if(r[i].a==-1) continue;
            if(r[i].b==max( max(r[i].a,r[i].b), r[i].c)){
                if(yy<(n/2)){
                    y+=r[i].b;
                    yy++;
                    r[i].a=-1,r[i].b=-1,r[i].c=-1;
                }
                else break;
            }
        }
        sort(r,r+n,cmpc);
        for(int i=0;i<n;i++){
            if(r[i].a==-1) continue;
            if(r[i].c==max( max(r[i].a,r[i].b), r[i].c)){
                if(zz<(n/2)){
                    z+=r[i].c;
                    zz++;
                    r[i].a=-1,r[i].b=-1,r[i].c=-1;
                }
                else break;
            }
        }
        sort(r,r+n,cmpa);
        for(int i=0;i<n;i++){
            if(r[i].a==-1) continue;
            if(r[i].a==max( max(r[i].a,r[i].b), r[i].c)){
                if(xx<(n/2)){
                    x+=r[i].a;
                    xx++;
                }
                else if(r[i].b==max(r[i].c,r[i].b)){
                    if(yy<(n/2)){
                        y+=r[i].b;
                        yy++;
                    }
                    else{
                        z+=r[i].c;
                        zz++;
                    }
                }
                else{
                    if(zz<(n/2)){
                        z+=r[i].c;
                        zz++;
                    }
                    else{
                        y+=r[i].b;
                        yy++;
                    }
                }
            }
            else if(r[i].b==max(r[i].c,r[i].b)){
                if(yy<(n/2)){
                    y+=r[i].b;
                    yy++;
                }
                else if(r[i].a==max(r[i].c,r[i].a)){
                    if(xx<(n/2)){
                        x+=r[i].a;
                    }
                    else{
                        z+=r[i].c;
                        zz++;
                    }
                }
                else{
                    if(zz<(n/2)){
                        z+=r[i].c;
                        zz++;
                    }
                    else{
                        x+=r[i].a;
                        xx++;
                    }
                }
            }
            else{
                if(zz<(n/2)){
                    z+=r[i].c;
                    zz++;
                }
                else if(r[i].a==max(r[i].b,r[i].a)){
                    if(xx<(n/2)){
                        x+=r[i].a;
                        xx++;
                    }
                    else{
                        y+=r[i].b;
                        yy++;
                    }
                }
                else{
                    if(yy<(n/2)){
                        y+=r[i].b;
                        yy++;
                    }
                    else{
                        x+=r[i].a;
                        xx++;
                    }
                }
            }
        }
        cout<<x+y+z<<endl;
    }
    return 0;
}
