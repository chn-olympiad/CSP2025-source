#include <bits/stdc++.h>
using namespace std;
struct nde{
    int a,b,c,sd,sz,dz,ab;
}s[100005];
int n,m,T,isb0,isc0,ina,inb,inc;
long long ans;
bool bmp(nde a,nde b){
    return a.a>b.a;
}
bool cmp(nde a,nde b){
    return a.ab>b.ab;
}
bool dmp(nde a,nde b){
    return a.sz>b.sz;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) s[i].a=s[i].b=s[i].c=s[i].sd=s[i].sz=s[i].dz=0;
        ans=0,ina=inb=inc=0,isb0=isc0=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
            if(s[i].a>=s[i].b&&s[i].a>=s[i].c){
                s[i].sd=1;
                s[i].sz=(s[i].a-s[i].b)+(s[i].a-s[i].c);
                if(s[i].b>=s[i].c) s[i].dz=s[i].b;
                else s[i].dz=s[i].c;
            }
            else if(s[i].b>s[i].a&&s[i].b>=s[i].c){
                s[i].sd=2;
                s[i].sz=(s[i].b-s[i].a)+(s[i].b-s[i].c);
                if(s[i].a>=s[i].c) s[i].dz=s[i].a;
                else s[i].dz=s[i].c;
            }
            else if(s[i].c>s[i].a&&s[i].c>s[i].b){
                s[i].sd=3;
                s[i].sz=(s[i].c-s[i].b)+(s[i].c-s[i].a);
                if(s[i].a>=s[i].b) s[i].dz=s[i].a;
                else s[i].dz=s[i].b;
            }
            if(s[i].b==0) isb0++;
            if(s[i].c==0) isc0++;
            s[i].ab=s[i].a-s[i].b;
        }
        if(n==2){
            cout<<max(s[1].a+s[2].b,max(s[1].a+s[3].c,max(s[1].b+s[2].a,max(s[1].b+s[2].c,max(s[1].c+s[2].b,s[1].c+s[2].a)))))<<endl;
            continue;
        }
        if(isb0==n&&isc0==n){
            sort(s+1,s+n+1,bmp);
            for(int i=1;i<=n/2;i++) ans+=s[i].a;
        }
        else if(isb0!=n&&isc0==n){
            sort(s+1,s+n+1,cmp);
            for(int i=1;i<=n/2;i++) {
                ans+=s[i].a;
            }
            for(int i=n/2+1;i<=n;i++) {
                ans+=s[i].b;
            }
        }
        else if(n<=200){
            sort(s+1,s+n+1,dmp);
            for(int i=1;i<=n;i++){
                if(s[i].sd==1){
                    if(ina>=n/2) ans+=s[i].dz;
                    else{
                        ans+=s[i].a;
                        ina++;
                    }
                }
                else if(s[i].sd==2){
                    if(inb>=n/2) ans+=s[i].dz;
                    else{
                        ans+=s[i].b;
                        inb++;
                    }
                }
                else if(s[i].sd==3){
                    if(inc>=n/2) ans+=s[i].dz;
                    else{
                        ans+=s[i].c;
                        inc++;
                    }
                }
            }
        }
        else{
            for(int i=1;i<=n;i++){
                ans+=max(s[i].a,max(s[i].b,s[i].c));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
