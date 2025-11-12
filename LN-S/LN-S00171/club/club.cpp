#include<bits/stdc++.h>
using namespace std;
int t;
struct ttt{
    int x,y,z;
    int xx,yy,zz,id;
}a[100005];
bool cmpx(ttt c,ttt d){
    return c.xx>d.xx;
}
bool cmpy(ttt c,ttt d){
    return c.yy>d.yy;
}
bool cmpz(ttt c,ttt d){
    return c.zz>d.zz;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int n,ans=0,as=0,bs=0,cs=0;
        bool b[100005];
        memset(b,0,sizeof(b));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            a[i].xx=(a[i].x-a[i].y)+(a[i].x-a[i].z);
            a[i].yy=(a[i].y-a[i].x)+(a[i].y-a[i].z);
            a[i].zz=(a[i].z-a[i].y)+(a[i].z-a[i].x);
            a[i].id=i;
//            cout<<a[i].xx<<' '<<a[i].yy<<' '<<a[i].zz;
        }
        sort(a+1,a+n+1,cmpx);
        for(int i=1;i<=n;i++){
            if(a[i].xx>a[i].yy&&a[i].xx>a[i].zz&&b[a[i].id]==0){
                ans+=a[i].x;
                b[a[i].id]=1;
                as++;
            }
            if(as==n/2)
                break;
        }
        sort(a+1,a+n+1,cmpy);
        for(int i=1;i<=n;i++){
            if(a[i].yy>a[i].xx&&a[i].yy>a[i].zz&&b[a[i].id]==0){
                ans+=a[i].y;
                b[a[i].id]=1;
                bs++;
            }
            if(bs==n/2)
                break;
        }
        if(as+bs<n){
            sort(a+1,a+n+1,cmpz);
            for(int i=1;i<=n;i++){
                if(a[i].zz>a[i].yy&&a[i].zz>a[i].xx&&b[a[i].id]==0){
                    ans+=a[i].z;
                    b[a[i].id]=1;
                    cs++;
                }
                if(cs==n/2)
                    break;
            }
        }
        if(as+bs+cs<n){
            if(as<n/2){
                sort(a+1,a+n+1,cmpx);
                for(int i=1;i<=n;i++){
                    if((a[i].xx>a[i].yy||a[i].xx>a[i].zz)&&b[a[i].id]==0){
                        ans+=a[i].x;
                        b[a[i].id]=1;
                        as++;
                    }
                    if(as==n/2||as+bs+cs==n)
                        break;
                }
            }
            if(bs<n/2&&as+bs+cs<n){
                sort(a+1,a+n+1,cmpy);
                for(int i=1;i<=n;i++){
                    if((a[i].yy>a[i].xx||a[i].yy>a[i].zz)&&b[a[i].id]==0){
                        ans+=a[i].y;
                        b[a[i].id]=1;
                        bs++;
                    }
                    if(bs==n/2||as+bs+cs==n)
                        break;
                }
            }
            if(cs<n/2&&as+bs+cs<n){
                sort(a+1,a+n+1,cmpz);
                for(int i=1;i<=n;i++){
                    if((a[i].zz>a[i].yy||a[i].zz>a[i].xx)&&b[a[i].id]==0){
                        ans+=a[i].z;
                        b[a[i].id]=1;
                        cs++;
                    }
                    if(cs==n/2||as+bs+cs==n)
                        break;
                }
            }
        }
        if(as+bs+cs<n){
            for(int i=1;i<=n;i++){
                if(b[a[i].id]==0){
                    if(a[i].xx<a[i].yy&&a[i].xx<a[i].zz&&as<n/2){
                        ans+=a[i].x;
                        as++;
                        b[a[i].id]=1;
                    }
                    if(as==n/2||as+bs+cs==n)
                        break;
                    if(a[i].yy<a[i].xx&&a[i].yy<a[i].zz&&bs<n/2){
                        ans+=a[i].y;
                        bs++;
                        b[a[i].id]=1;
                    }
                    if(bs==n/2||as+bs+cs==n)
                        break;
                    if(a[i].zz<a[i].yy&&a[i].zz<a[i].xx&&cs<n/2){
                        ans+=a[i].z;
                        cs++;
                        b[a[i].id]=1;
                    }
                    if(cs==n/2||as+bs+cs==n)
                        break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
