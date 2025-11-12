#include<bits/stdc++.h>
#define reg register
// #define int long long
inline int read(){
    reg int x=0,k=1; reg char ch=getchar();
    while (ch<'0'||ch>'9') (ch=='-')&&(k=-1),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*k; 
}
const int N=5e6+10;
int n,q;
#define ull unsigned long long
const ull pw=131,mod=1e9+7;
int len[N];
ull hsh1[N],hsh2[N],h1[N],h2[N],Pw[N];
char str[N],s1[N],s2[N];
inline ull get1(reg int l,reg int r){
    return (h1[r]+mod-h1[l-1]*Pw[r-l+1]%mod)%mod;
}
inline ull get2(reg int l,reg int r){
    return (h2[r]+mod-h2[l-1]*Pw[r-l+1]%mod)%mod;
}
signed main(){
    freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
    n=read(),q=read();
    for (reg int i=1;i<=n;i++){
        scanf("%s",str+1);
        for (reg int j=1;str[j];j++) hsh1[i]=(hsh1[i]*pw+str[j]-'a'+1)%mod;
        scanf("%s",str+1);
        for (reg int j=1;str[j];j++) hsh2[i]=(hsh2[i]*pw+str[j]-'a'+1)%mod;
        len[i]=strlen(str+1);
    }
    while (q--){
        reg int L,R;
        scanf("%s%s",s1+1,s2+1);
        reg int Len=strlen(s1+1);
        Pw[0]=1; for (reg int i=1;i<=Len;i++) Pw[i]=Pw[i-1]*pw%mod;
        for (reg int i=1;i<=Len;i++) h1[i]=(h1[i-1]*pw+s1[i]-'a'+1)%mod;
        for (reg int i=1;i<=Len;i++) h2[i]=(h2[i-1]*pw+s2[i]-'a'+1)%mod;
        for (reg int i=1;i<=Len;i++) if (s1[i]!=s2[i]){L=i;break;}
        for (reg int i=Len;i;i--) if (s1[i]!=s2[i]){R=i;break;}
        reg int ans=0;
        for (reg int i=R;i<=Len;i++){
            for (reg int j=1;j<=n;j++){
                if (i<len[j]) continue;
                reg int l=i-len[j]+1,r=i;
                if (hsh1[j]!=get1(l,r)) continue;
                if (hsh2[j]!=get2(l,r)) continue;
                if (get1(1,l-1)!=get2(1,l-1)) continue;
                if (get1(r+1,Len)!=get2(r+1,Len)) continue;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}