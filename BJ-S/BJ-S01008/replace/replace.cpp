#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define fr first
#define sc second
#define mk make_pair
#define pb push_back
const int MAXN=5000010,MAXM=1000010,N=15,inf=1e9,base=200007,base2=200003,Mod=1011451423,Mod2=998244853;
int read(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();return x*f;}
int n,q,a[MAXN];
char s1[MAXN],s2[MAXN];
unordered_map<ull,int>mp,mp2;
pii s[MAXN],jc[MAXN];bool ck[MAXN];
pii Hsh(pii x,char y,char z){return mk(((ll)x.fr*base+y*131ll+z)%Mod,((ll)x.sc*base2+y*131ll+z)%Mod2);}
ull to(pii x){return ((ull)x.fr)<<31|x.sc;}
pii qry(int l,int r){return mk((s[r].fr-(ll)s[l-1].fr*jc[r-l+1].fr%Mod+Mod)%Mod,(s[r].sc-(ll)s[l-1].sc*jc[r-l+1].sc%Mod2+Mod2)%Mod2);}
void slv(){
    n=read(),q=read();
    for(int o=1;o<=n;o++){
        scanf("%s",s1+a[o-1]+1);
        scanf("%s",s2+a[o-1]+1);
        int k=strlen(s1+a[o-1]+1);
        a[o]=a[o-1]+k;
        pii hs=mk(0,0);
        for(int i=a[o-1]+1;i<=a[o];i++)
        ck[i]=s1[i]==s2[i],
        s[i]=hs=Hsh(hs,s1[i],s2[i]);
        mp[to(hs)]++;
    }
    for(int o=1;o<=n;o++){
        int sum=0;
        for(int i=a[o-1]+1;i<=a[o];i++){
            if(!ck[i])sum=0;
            sum+=mp.count(to(s[i]))?mp[to(s[i])]:0;
            mp2[to(s[i])]=sum;
        }
    }
    while(q--){
        scanf("%s",s1+1);
        scanf("%s",s2+1);
        int k=strlen(s1+1),k2=strlen(s2+1);
        if(k!=k2){
            puts("0");
            continue;
        }
        pii hs=mk(0,0);
        int L=0,R=0;
        ll res=0;
        for(int i=1;i<=k;i++){
            s[i]=hs=Hsh(hs,s1[i],s2[i]);
            if(s1[i]!=s2[i])L=L?L:i,R=i;
        }
        for(int i=1;i<=L;i++){
            int l=R-1,r=k;
            while(l<r){
                int mid=(l+r+1)>>1;
                if(mp2.count(to(qry(i,mid))))l=mid;
                else r=mid-1;
            }
            if(l>=R)res+=mp2[to(qry(i,l))];
        }
        printf("%lld\n",res);
    }
}
signed main(){
    freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
    jc[0]={1,1};
    for(int i=1;i<=MAXN-5;i++)jc[i].fr=(ll)jc[i-1].fr*base%Mod,jc[i].sc=(ll)jc[i-1].sc*base2%Mod2;
    slv();
    cerr<<(clock()*1.0)/CLOCKS_PER_SEC<<"s\n";
    return 0;
}