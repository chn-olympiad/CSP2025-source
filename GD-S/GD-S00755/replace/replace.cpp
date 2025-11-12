#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define eb emplace_back
#define ep emplace
#define pii pair<int,int>
#define puu pair<ull,ull>
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
const int maxn=2e5+10,maxL=5e6+10;
mt19937_64 matt(time(0));
bool mem1;
const ull bs=173,bss=1719,b2=1145147595432457ull,bs2=1919843281758351ull;
const int B=5000;
int n,q;
string a[maxn],b[maxn],sq[maxn],tq[maxn];
pii p[maxn];
ull H[maxn],P[maxn],S[maxn],pre[maxn],suf[maxn];
ull H2[maxn],P2[maxn],S2[maxn],pre2[maxn],suf2[maxn];
int tot,cur;
map<puu,int> mp,mp2[maxn];
vector<int> vec[maxn],v2[maxn];
bool mem2;
bool chk(string ss){
    int bb=0;
    for(int i=0;i<ss.length();i++){
        if(ss[i]!='a'&&ss[i]!='b')    return false;
        bb+=(ss[i]=='b');
    }
    return bb==1;
}
namespace spB{
    bool check(){for(int i=1;i<=n;i++)if(!chk(a[i])||!chk(b[i]))return false;for(int i=1;i<=q;i++)if(!chk(sq[i])||!chk(tq[i]))return false;return true;}
    void solve(){
        debug("special B\n");
        for(int i=1;i<=n;i++){
            int m=a[i].length();p[i].fi=-1;p[i].se=0;
            for(int j=0;j<m;j++)if(a[i][j]!=b[i][j]){p[i].fi=j;break;}
            for(int j=m-1;~j;j--)if(a[i][j]!=b[i][j]){p[i].se=j;break;}
            if(!~p[i].fi)   continue;
            for(int j=p[i].fi;j<=p[i].se;j++)   H[i]=H[i]*bs+a[i][j]*bss+b[i][j],H2[i]=H2[i]*b2+a[i][j]*bs2+b[i][j];
            for(int j=p[i].fi-1;j>=0;j--)	P[i]=P[i]*bs+a[i][j],P2[i]=P2[i]*b2+a[i][j];
            for(int j=p[i].se+1;j<m;j++)    S[i]=S[i]*bs+a[i][j],S2[i]=S2[i]*b2+a[i][j];
            p[i].se=m-p[i].se-1;
            if(mp.find(puu(H[i],H2[i]))==mp.end())  mp[puu(H[i],H2[i])]=++tot;
            vec[mp[puu(H[i],H2[i])]].eb(i);
            ull h1=P[i]*bs+H[i],h2=P2[i]*b2+H2[i];
            int &x=mp2[p[i].fi][puu(h1,h2)];
            if(!x)  x=++cur;
            v2[x].eb(p[i].se);
        }
        for(int i=1;i<=cur;i++) sort(v2[i].begin(),v2[i].end());
        for(int _=1;_<=q;_++){
            string s=sq[_],t=tq[_],x="",y="",yy="",z="";
        	int m=s.length();
            ull dif=0,dif2=0;
            int l=0,r=0;
            for(int i=0;i<m;i++)if(s[i]!=t[i]){l=i;break;}else x+=s[i];
            for(int i=m-1;~i;i--)if(s[i]!=t[i]){r=i;break;}else z+=t[i];
            reverse(z.begin(),z.end());
            for(int i=l;i<=r;i++)   y+=s[i],yy+=t[i],dif=dif*bs+s[i]*bss+t[i],dif2=dif2*b2+s[i]*bs2+t[i];
            int len=x.length();
            for(int i=1;i<=len;i++) pre[i]=pre[i-1]*bs+x[len-i],pre2[i]=pre2[i-1]*b2+x[len-i];
            len=z.length();
            for(int i=1;i<=len;i++) suf[i]=suf[i-1]*bs+z[i-1],suf2[i]=suf2[i-1]*b2+z[i-1];
            if(mp.find(puu(dif,dif2))==mp.end()){
                cout<<"0\n";
                continue;
            }
            int ans=0;
            for(int j=x.length();~j;j--){
                ull h1=pre[j]*bs+dif,h2=pre2[j]*b2+dif2;
                if(mp2[j].find(puu(h1,h2))==mp2[j].end()) continue;
                int id=mp2[j][puu(h1,h2)];
                // for(int i:v2[id])   ans+=(p[i].se<=z.length()&&suf[p[i].se]==S[i]&&suf2[p[i].se]==S2[i]);
                ans+=upper_bound(v2[id].begin(),v2[id].end(),z.length())-v2[id].begin();
            }
            cout<<ans<<'\n';
        }
    }
}
int main(){
    freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
    // debug("%.2fMB\n",abs(&mem1-&mem2)/1024./1024);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)   cin>>a[i]>>b[i];
    for(int i=1;i<=q;i++)   cin>>sq[i]>>tq[i];
    if(spB::check())    return spB::solve(),0;
    for(int i=1;i<=n;i++){
        int m=a[i].length();p[i].fi=-1;p[i].se=0;
        for(int j=0;j<m;j++)if(a[i][j]!=b[i][j]){p[i].fi=j;break;}
        for(int j=m-1;~j;j--)if(a[i][j]!=b[i][j]){p[i].se=j;break;}
        if(!~p[i].fi)   continue;
        for(int j=p[i].fi;j<=p[i].se;j++)   H[i]=H[i]*bs+a[i][j]*bss+b[i][j],H2[i]=H2[i]*b2+a[i][j]*bs2+b[i][j];
        for(int j=p[i].fi-1;j>=0;j--)	P[i]=P[i]*bs+a[i][j],P2[i]=P2[i]*b2+a[i][j];
        for(int j=p[i].se+1;j<m;j++)    S[i]=S[i]*bs+a[i][j],S2[i]=S2[i]*b2+a[i][j];
        p[i].se=m-p[i].se-1;
        if(mp.find(puu(H[i],H2[i]))==mp.end())  mp[puu(H[i],H2[i])]=++tot;
        vec[mp[puu(H[i],H2[i])]].eb(i);
        ull h1=P[i]*bs+H[i],h2=P2[i]*b2+H2[i];
        int &x=mp2[p[i].fi][puu(h1,h2)];
        if(!x)  x=++cur;
        v2[x].eb(i);
        // printf("%d %d %d\n",i,p[i].fi,p[i].se);
    }
    for(int _=1;_<=q;_++){
        string s=sq[_],t=tq[_],x="",y="",yy="",z="";
        int m=s.length();
        ull dif=0,dif2=0;
        int l=0,r=0;
        for(int i=0;i<m;i++)if(s[i]!=t[i]){l=i;break;}else x+=s[i];
        for(int i=m-1;~i;i--)if(s[i]!=t[i]){r=i;break;}else z+=t[i];
        reverse(z.begin(),z.end());
        for(int i=l;i<=r;i++)   y+=s[i],yy+=t[i],dif=dif*bs+s[i]*bss+t[i],dif2=dif2*b2+s[i]*bs2+t[i];
        int len=x.length();
        for(int i=1;i<=len;i++) pre[i]=pre[i-1]*bs+x[len-i],pre2[i]=pre2[i-1]*b2+x[len-i];
        len=z.length();
        for(int i=1;i<=len;i++) suf[i]=suf[i-1]*bs+z[i-1],suf2[i]=suf2[i-1]*b2+z[i-1];
        if(mp.find(puu(dif,dif2))==mp.end()){
            cout<<"0\n";
            continue;
        }
        len=x.length()+z.length();
        if((len>B)||(!q)){
            int ans=0,id=mp[puu(dif,dif2)];
            for(int i:vec[id]){
                // printf("%d %d %d\n",P[i],H[i],S[i]);
                // printf("%d %d %d\n",pre[p[i].fi],dif,suf[p[i].se]);
                if((!~p[i].fi)||p[i].fi>x.length()||p[i].se>z.length())   continue;
                ans+=(pre[p[i].fi]==P[i]&&suf[p[i].se]==S[i]&&pre2[p[i].fi]==P2[i]&&suf2[p[i].se]==S2[i]);
            }
            cout<<ans<<'\n';
        }
        else{
            int ans=0;
            for(int j=x.length();~j;j--){
                ull h1=pre[j]*bs+dif,h2=pre2[j]*b2+dif2;
                if(mp2[j].find(puu(h1,h2))==mp2[j].end()) continue;
                int id=mp2[j][puu(h1,h2)];
                for(int i:v2[id])   ans+=(p[i].se<=z.length()&&suf[p[i].se]==S[i]&&suf2[p[i].se]==S2[i]);
            }
            cout<<ans<<'\n';
        }
    }
}