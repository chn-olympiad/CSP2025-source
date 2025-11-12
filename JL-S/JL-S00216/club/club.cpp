#include<bits/stdc++.h>
using namespace std;
struct aa{
    long long a;
    long long b;
    long long c;
    long long c12;
    long long c23;
    long long c13;
    long long h1213;
    long long h1223;
    long long h1323;
};
aa x[100010],a[100010],b[100010],c[100010];
long long t,n,ta,tb,tc,g;
bool cmpa(aa a,aa b){
    return a.h1213>b.h1213;
}
bool cmpb(aa a,aa b){
    return a.h1223>b.h1223;
}
bool cmpc(aa a,aa b){
    return a.h1323>b.h1323;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        ta=0;
        tb=0;
        tc=0;
        g=0;
        for(int j=0;j<n;j++){
            cin>>x[i].a>>x[i].b>>x[i].c;
            if(x[i].a>=x[i].b&&x[i].a>=x[i].c){
                a[ta].a=x[i].a;
                a[ta].b=x[i].b;
                a[ta].c=x[i].c;
                a[ta].c12=int(abs(x[i].a-x[i].b));
                a[ta].c13=int(abs(x[i].a-x[i].c));
                a[ta].c23=int(abs(x[i].b-x[i].c));
                a[ta].h1213=a[ta].c12+a[ta].c13;
                a[ta].h1223=a[ta].c12+a[ta].c23;
                a[ta].h1323=a[ta].c13+a[ta].c23;
                ta++;
            }else   if(x[i].b>=x[i].a&&x[i].b>=x[i].c){
                b[tb].a=x[i].a;
                b[tb].b=x[i].b;
                b[tb].c=x[i].c;
                b[tb].c12=int(abs(x[i].a-x[i].b));
                b[tb].c13=int(abs(x[i].a-x[i].c));
                b[tb].c23=int(abs(x[i].b-x[i].c));
                b[tb].h1213=b[tb].c12+b[tb].c13;
                b[tb].h1223=b[tb].c12+b[tb].c23;
                b[tb].h1323=b[tb].c13+b[tb].c23;
                tb++;
            }else{
                c[tc].a=x[i].a;
                c[tc].b=x[i].b;
                c[tc].c=x[i].c;
                c[tc].c12=int(abs(x[i].a-x[i].b));
                c[tc].c13=int(abs(x[i].a-x[i].c));
                c[tc].c23=int(abs(x[i].b-x[i].c));
                c[tc].h1213=c[tc].c12+c[tc].c13;
                c[tc].h1223=c[tc].c12+c[tc].c23;
                c[tc].h1323=c[tc].c13+c[tc].c23;
                tc++;
            }
        }
        sort(a,a+ta,cmpa);
        sort(b,b+tb,cmpb);
        sort(c,c+tc,cmpc);
        if(2*ta>n){
            for(int j=n/2;j<ta;j++){
                if(a[j].c12<=a[j].c13){
                    b[tb].a=a[j].a;
                    b[tb].b=a[j].b;
                    b[tb].c=a[j].c;
                    b[tb].c12=a[j].c12;
                    b[tb].c13=a[j].c13;
                    b[tb].c23=a[j].c23;
                    b[tb].h1213=a[j].h1213;
                    b[tb].h1223=a[j].h1223;
                    b[tb].h1323=a[j].h1323;
                    tb++;
                }
                if(a[j].c12>=a[j].c13){
                    c[tc].a=a[j].a;
                    c[tc].b=a[j].b;
                    c[tc].c=a[j].c;
                    c[tc].c12=a[j].c12;
                    c[tc].c13=a[j].c13;
                    c[tc].c23=a[j].c23;
                    c[tc].h1213=a[j].h1213;
                    c[tc].h1223=a[j].h1223;
                    c[tc].h1323=a[j].h1323;
                    tc++;
                }
            }
            ta=n/2;
            }
            if(2*tb>n){
                for(int j=n/2;j<tb;j++){
                if(b[j].c12<=b[j].c23){
                    a[ta].a=b[j].a;
                    a[ta].b=b[j].b;
                    a[ta].c=b[j].c;
                    a[ta].c12=b[j].c12;
                    a[ta].c13=b[j].c13;
                    a[ta].c23=b[j].c23;
                    a[ta].h1213=b[j].h1213;
                    a[ta].h1223=b[j].h1223;
                    a[ta].h1323=b[j].h1323;
                    ta++;
                }
                if(b[j].c12>=b[j].c23){
                    c[tc].a=b[j].a;
                    c[tc].b=b[j].b;
                    c[tc].c=b[j].c;
                    c[tc].c12=b[j].c12;
                    c[tc].c13=b[j].c13;
                    c[tc].c23=b[j].c23;
                    c[tc].h1213=b[j].h1213;
                    c[tc].h1223=b[j].h1223;
                    c[tc].h1323=b[j].h1323;
                    tc++;
                }
            }
            tb=n/2;
        }
        if(2*tc>n){
            for(int j=n/2;j<tc;j++){
                if(c[j].c13<=c[j].c23){
                    a[ta].a=c[j].a;
                    a[ta].b=c[j].b;
                    a[ta].c=c[j].c;
                    a[ta].c12=c[j].c12;
                    a[ta].c13=c[j].c13;
                    a[ta].c23=c[j].c23;
                    a[ta].h1213=c[j].h1213;
                    a[ta].h1223=c[j].h1223;
                    a[ta].h1323=c[j].h1323;
                    tb++;
                }
                if(c[j].c13>=c[j].c23){
                    b[tb].a=c[j].a;
                    b[tb].b=c[j].b;
                    b[tb].c=c[j].c;
                    b[tb].c12=c[j].c12;
                    b[tb].c13=c[j].c13;
                    b[tb].c23=c[j].c23;
                    b[tb].h1213=c[j].h1213;
                    b[tb].h1223=c[j].h1223;
                    b[tb].h1323=c[j].h1323;
                        tb++;
                    }
                }
                tc=n/2;
            }
        for(int j=0;j<ta;j++){
            g=g+a[j].a;
        }
        for(int j=0;j<tb;j++){
            g=g+b[j].b;
        }
        for(int j=0;j<tc;j++){
            g=g+c[j].c;
        }
        cout<<g<<endl;
    }
    return 0;
}
