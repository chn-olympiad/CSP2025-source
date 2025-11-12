#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct d{
    ll a,b,c;
}s[100005];
struct dd{
    ll v,id,vv;
}av[100005],bv[100005],cv[100005];
ll n,t,ans,a,b,c,al,bl,cl,k[100005];
bool cmp(dd x,dd y){
    if(x.vv==y.vv) return x.v<y.v;
    return x.vv<y.vv;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;
        }
        memset(av,0,sizeof av);
        memset(bv,0,sizeof bv);
        memset(cv,0,sizeof cv);
        a=b=c=ans=al=bl=cl=0;
        for(int i=1;i<=n;i++){
            ll aa=s[i].a,bb=s[i].b,cc=s[i].c;
            if(max({aa,bb,cc})==aa)a++,ans+=aa;
            else if(max({aa,bb,cc})==bb) b++,ans+=bb;
            else c++,ans+=cc;
        }
        if(max({a,b,c})<=n/2){
            cout<<ans<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            ll aa=s[i].a,bb=s[i].b,cc=s[i].c;
            if(max({aa,bb,cc})==aa)av[++al].id=i,av[al].v=aa,av[al].vv=aa-max(cc,bb),k[i]=av[al].vv;
            else if(max({aa,bb,cc})==bb)bv[++bl].id=i,bv[al].v=bb,bv[bl].vv=bb-max(aa,cc),k[i]=bv[bl].vv;
            else cv[++cl].id=i,cv[cl].v=cc,cv[cl].vv=cc-max(aa,bb),k[i]=cv[cl].vv;
        }
        if(a>n/2){
            a=b=c=ans=0;
            sort(av+1,av+al+1,cmp);
            for(int i=1;i<=bl;i++) ans+=s[bv[i].id].b;
            for(int i=1;i<=cl;i++) ans+=s[cv[i].id].c;
            for(int i=1;i<=al-(n/2);i++){
                ll id=av[i].id;
                ans+=max(s[id].b,s[id].c);
            }
            for(int i=al;i>=al-n/2+1;i--){
                ll id=av[i].id;
                ans+=s[id].a;
            }
            //cout<<"a ";
        }else if(b>n/2){
            a=b=c=ans=0;
            sort(bv+1,bv+bl+1,cmp);
            for(int i=1;i<=al;i++) ans+=s[av[i].id].a;
            for(int i=1;i<=cl;i++) ans+=s[cv[i].id].c;
            for(int i=1;i<=bl-(n/2);i++){
                ll id=bv[i].id;
                ans+=max(s[id].a,s[id].c);
            }
            for(int i=bl;i>=bl-n/2+1;i--){
                ll id=bv[i].id;
                ans+=s[id].b;
            }
            //cout<<"b ";
        }else{
            a=b=c=ans=0;
            sort(cv+1,cv+cl+1,cmp);
            for(int i=1;i<=bl;i++) ans+=s[bv[i].id].b;
            for(int i=1;i<=al;i++) ans+=s[av[i].id].a;
            for(int i=1;i<=cl-(n/2);i++){
                //cout<<cv[i].id<<" ";
                ll id=cv[i].id;
                ans+=max(s[id].b,s[id].a);
            }
            for(int i=cl;i>=(cl-(n/2))+1;i--){
                ll id=cv[i].id;
                //cout<<id<<" ";
                ans+=s[id].c;
            }
            //cout<<"c ";
        }
        cout<<ans<<endl;
    }
    return 0;
}
