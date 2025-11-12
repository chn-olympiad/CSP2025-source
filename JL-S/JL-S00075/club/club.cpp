#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct club{int a,b,c,mx,md,mn,f;}x[N];
int t,n,ans=-1,ix,iy,iz,mb=-1,mc=-1;
bool cmp(club x,club y){return x.a>y.a;}
bool cmpp(club x,club y){return abs(x.a-x.b)<abs(y.a-y.b);}
bool cmpa(club x,club y){return abs(x.a-x.md)<abs(y.a-x.md);}
bool cmpb(club x,club y){return abs(x.b-x.md)<abs(y.b-x.md);}
bool cmpc(club x,club y){return abs(x.c-x.md)<abs(y.c-x.md);}
void dfs(int ax,int ay,int az,int i,int sum){
    if(i==n+1)ans=max(ans,sum);
    if(ax<n/2)dfs(ax+1,ay,az,i+1,sum+x[i].a);
    if(ay<n/2)dfs(ax,ay+1,az,i+1,sum+x[i].b);
    if(az<n/2)dfs(ax,ay,az+1,i+1,sum+x[i].c);
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;ans=0;
        for(int i=1;i<=n;i++){
            cin>>ix>>iy>>iz;
            if(ix>iy&&ix>iz){
                if(iy>iz)x[i]={ix,iy,iz,ix,iy,iz};
                else x[i]={ix,iy,iz,ix,iz,iy};
            }
            else if(iy>ix&&iy>iz){
                if(ix>iz)x[i]={ix,iy,iz,iy,ix,iz};
                else x[i]={ix,iy,iz,iy,iz,ix};
            }
            else{
                if(ix>iy)x[i]={ix,iy,iz,iz,ix,iy};
                else x[i]={ix,iy,iz,iz,iy,ix};
            }
            mb=max(mb,x[i].b),mc=max(mc,x[i].c);
        }
        if(n<=10){dfs(0,0,0,1,0);cout<<ans<<'\n';continue;}
        if(mb==0&&mc==0){
            sort(x+1,x+1+n,cmp);
            for(int i=1;i<=n/2;i++)ans+=x[i].a;
            cout<<ans<<'\n';
            continue;
        }
        if(mc==0){
            int na=0,nb=0;
            for(int i=1;i<=n;i++){if(x[i].mx==x[i].a)na++,ans+=x[i].a;else nb++,ans+=x[i].b;}
            if(abs(na-nb)){
                sort(x+1,x+1+n,cmpp);
                for(int i=1;i<=abs(na-nb);i++)ans-=abs(x[i].a-x[i].b);
            }
            cout<<ans<<'\n';
            continue;
        }
        int na=0,nb=0,nc=0;
        for(int i=1;i<=n;i++){
            if(x[i].mx==x[i].a)na++,ans+=x[i].a,x[i].f=1;
            else if(x[i].mx==x[i].b)nb++,ans+=x[i].b,x[i].f=2;
            else nc++,ans+=x[i].c,x[i].f=3;
        }
        if(na>n/2){
            sort(x+1,x+1+n,cmpa);
            for(int i=1;i<=n,na>n/2;i++)if(x[i].f==1){ans-=x[i].a-(x[i].b>x[i].c?x[i].b:x[i].c),na--;if((x[i].b>x[i].c?x[i].b:x[i].c)==x[i].b)nb++;else nc++;}
        }
        if(nb>n/2){
            sort(x+1,x+1+n,cmpb);
            for(int i=1;i<=n,nb>n/2;i++)if(x[i].f==2){ans-=x[i].b-(x[i].a>x[i].c?x[i].a:x[i].c),nb--;if((x[i].a>x[i].c?x[i].a:x[i].c)==x[i].a)na++;else nc++;}
        }
        if(nc>n/2){
            sort(x+1,x+1+n,cmpc);
            for(int i=1;i<=n,nc>n/2;i++)if(x[i].f==3){ans-=x[i].c-(x[i].a>x[i].b?x[i].a:x[i].b),nc--;if((x[i].a>x[i].b?x[i].a:x[i].b)==x[i].b)nb++;else na++;}
        }
        cout<<ans<<'\n';
    }
    return 0;
}
