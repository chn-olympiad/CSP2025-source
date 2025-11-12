#include <bits/stdc++.h>
using namespace std;
long long a,b,c=1,d=1,e=1,t,p[1000000],o[1000000],y[1000000],u[1000000],s[1000000],z[1000000],r=0,w,m[100];
long long x,v,g;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>a;
        if(a==2){
            cin>>p[1]>>o[1]>>y[1];
            cin>>p[2]>>o[2]>>y[2];
            m[1]=p[1]+o[2];
            m[2]=p[1]+y[2];
            m[3]=o[1]+p[2];
            m[4]=o[1]+y[2];
            m[5]=y[1]+p[2];
            m[6]=y[1]+o[2];
            m[7]=p[2]+o[1];
            m[8]=p[2]+y[1];
            m[9]=o[2]+p[1];
            m[10]=o[2]+y[1];
            m[11]=y[2]+o[1];
            m[12]=y[2]+p[1];
            sort(m+1,m+13);
            cout<<m[12]<<'\n';
        }else{
        for(int j=1;j<=a;j++){
            u[j]=99999999;
            s[j]=99999999;
            z[j]=99999999;
        }
        for(int j=1;j<=a;j++){
            cin>>p[j]>>o[j]>>y[j];
            if(p[j]>o[j]&&p[j]>y[j]){
                u[c]=p[j];
                c++;
            }
            if(o[j]>p[j]&&o[j]>y[j]){
                s[d]=o[j];
                d++;
            }
            if(y[j]>o[j]&&y[j]>p[j]){
                z[e]=y[j];
                e++;
            }
        }
        if(c-1<=a/2&&d-1<=a/2&&e-1==a/2){
            for(int j=1;j<=a;j++){
                r+=u[j]+s[j]+z[j];
            }
            cout<<r<<'\n';
            r=0;
            for(int j=1;j<=a;j++){
            if(u[j]!=99999999){
                r+=u[j];
            }if(s[j]!=99999999){
                r+=s[j];
            }if(z[j]!=99999999){
                r+=z[j];
            }
        }
        }else if(c-1>a/2){
            sort(u+1,u+c);
            x=c;
            for(int j=1;j<=x-1-a/2;j++){
                for(int k=1;k<=a;k++){
                    if(u[j]==p[k]){
                        c--;
                        w=max(o[k],y[k]);
                        if(w==o[k]&&d<=a/2){
                            d++;
                            s[d]=w;
                            u[j]=0;
                        }else if(w==y[k]&&e<=a/2){
                            e++;
                            z[e]=w;
                            u[j]=0;
                        }
                    }
                }
            }
        }else if(d-1>a/2){
            sort(s+1,s+d);
            v=d;
            for(int j=1;j<=v-1-a/2;j++){
                for(int k=1;k<=a;k++){
                    if(s[j]==o[k]){
                        d--;
                        w=max(p[k],y[k]);
                        if(w==p[k]&&c-1<=a/2){
                            c++;
                            u[c]=w;
                            s[j]=0;
                        }else if(w==y[k]&&e-1<=a/2){
                            e++;
                            z[e]=w;
                            s[j]=0;
                        }
                    }
                }
            }
        }else if(e-1>a/2){
            sort(z+1,z+e);
            g=e;
            for(int j=1;j<=g-1-a/2;j++){
                for(int k=1;k<=a;k++){
                    if(z[j]==y[k]){
                        e--;
                        w=max(o[k],p[k]);
                        if(w==o[k]&&d-1<=a/2){
                            d++;
                            s[d]=w;
                            z[j]=0;
                        }else if(w==p[k]&&c-1<=a/2){
                            c++;
                            u[c]=w;
                            z[j]=0;
                        }
                    }
                }
            }
        }
        for(int j=1;j<=a;j++){
            if(u[j]!=99999999){
                r+=u[j];
            }if(s[j]!=99999999){
                r+=s[j];
            }if(z[j]!=99999999){
                r+=z[j];
            }
        }
        cout<<r<<'\n';
        r=0;
        c=0;
        d=0;
        e=0;
        }
    }
    return 0;
}
