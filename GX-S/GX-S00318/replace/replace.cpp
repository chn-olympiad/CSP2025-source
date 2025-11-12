#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define qwq Ff472130
#define f(i,l,r) for (int i=l;i<=r;i++)
#define F(i,r,l) for (int i=r;i>=l;i--)
const int N=2e5+10;
const int inf=1e9+7;

inline void read(int &x) {
    x=0;
    char ch=getchar();
    while (ch<48) ch=getchar();
    while (ch>=48) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}

int n,q;
int l[N];
char s1[N],s2[N];
ll h1[N],h2[N],ml[N];
ll gs[N],gt[N];

const int B=131,mod=19491001;
map<int,int> mp;

inline ll H(char *s) {
    ll res=0;
    int k=strlen(s);
    f(i,1,k) res=res*B+(s[i]-'a'+1)%mod;
    return res;
}

inline void get(int len) {
    ml[0]=1;
    f(i,1,len) {
        h1[i]=h1[i-1]*B+(s1[i]-'a'+1);
        h2[i]=h2[i-1]*B+(s2[i]-'a'+1);
        h1[i]%=mod;h2[i]%=mod;
        ml[i]=ml[i-1]*B%mod;
    }
}

inline ll r1(int l,int r) {
    return (h1[r]-h1[l]*ml[r-l]%mod+mod)%mod;
}

inline ll r2(int l,int r) {
    return (h2[r]-h2[l]*ml[r-l]%mod+mod)%mod;
}

int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    read(n);read(q);
    f(i,1,n) {
        scanf("%s%s",s1+1,s2+1);
        ll H1=H(s1),H2=H(s2);
        l[i]=strlen(s1+1);
        gs[i]=H1;
        gt[i]=H2;
    }
    while (q--) {
        scanf("%s%s",s1+1,s2+1);
        if (strlen(s1+1)!=strlen(s2+1)) {
            puts("0");
            continue;
        }
        int s=0,t=0,len=strlen(s1+1),ans=0;
        f(i,1,len) {
            if (s1[i]!=s2[i]) {
                if (!s) s=i;
                t=i;
            }
        }
        get(len);
        f(i,1,s) f(j,1,n) {
            if (i+l[j]-1<t) continue;
            if (i+l[j]-1>n) continue;
            if (r1(i,i+l[j]-1)==gs[j]&&r2(i,i+l[j]-1)==gt[j]) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
