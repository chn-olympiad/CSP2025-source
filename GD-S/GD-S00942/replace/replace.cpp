#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>

#define LL long long
#define pLL pair<LL,LL>

using namespace std;

void FileIO(string File) {
    freopen((File+".in").c_str(),"r",stdin);
    freopen((File+".out").c_str(),"w",stdout);
}
LL read() {
    LL x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

const LL N=2e5+5;
const LL L=5e6+5;
const LL BASE=131;

LL n,q;
string s,t;
LL len[N];
LL pw[L];
LL l;
unsigned LL hsf[N],hss[N],qhsf[L],qhss[L];

inline unsigned LL calc(unsigned LL *hs,LL l,LL r) {
    if(l>r) return 0;
    return hs[r]-hs[l-1]*pw[r-l+1];
}

int main() {
    FileIO("replace");
    pw[0]=1;
    for(register int i=1;i<L;++i) {
        pw[i]=pw[i-1]*BASE;
    }
    n=read(),q=read();
    for(register int i=1;i<=n;++i) {
        cin>>s>>t;
        len[i]=s.size();
        s=":"+s;
        t="/"+t;
        for(int j=1;j<=len[i];j++) {
            hsf[i]=hsf[i]*BASE+s[j];
            hss[i]=hss[i]*BASE+t[j];
        }
    }
    // for(int i=1;i<=n;i++) {
    //     printf("!%u %u\n",hsf[i],hss[i]);
    // }
    for(register int i=1;i<=q;++i) {
        cin>>s>>t;
        if(s.size()!=t.size()) {
            printf("0\n");
            continue;
        }
        l=s.size();
        s=":"+s;
        t="/"+t;
        qhsf[1]=s[1];
        qhss[1]=t[1];
        for(register int j=2;j<=l;++j) {
            qhsf[j]=qhsf[j-1]*BASE+s[j];
            qhss[j]=qhss[j-1]*BASE+t[j];
        }
        LL ans=0;
        for(register int j=0;j<l;++j) {
            if(calc(qhsf,1,j)!=calc(qhss,1,j)) {
                break;
            }
            for(register int i=1;i<=n;++i) {
                if(j+len[i]>l) continue;
                if(calc(qhsf,j+1,j+len[i])==hsf[i]&&calc(qhss,j+1,j+len[i])==hss[i]&&calc(qhsf,j+len[i]+1,l)==calc(qhss,j+len[i]+1,l)) {
                    ans++;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}