#include <bits/stdc++.h>
#define ull long long
#define base 13331
#define mod 1000000007ll
#define N1 200002
#define N2 5000002

using namespace std;

int n,q;
ull s1[N1],s2[N1];
int len[N1];
string t1,t2;
ull t1_s[N2],t2_s[N2];
int ans;
ull pmod[N2]={base};

ull read(int i){
    ull res=0;
    char c=getchar();
    while(c<'a' || c>'z')   c=getchar();
    while('a'<=c && c<='z'){
        len[i]++;
        res=(res*base+c)%mod;
        c=getchar();
    }
    return res;
}

ull __hash(ull (&s)[N2],int l,int r){
    return (s[r]-s[l-1]*pmod[r-l]%mod+mod)%mod;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    for(int i=1;i<=N2;i++)  pmod[i]=pmod[i-1]*base%mod;
    scanf("%d%d\n",&n,&q);
    for(int i=1;i<=n;i++)   s1[i]=read(i),s2[i]=read(i),len[i]>>=1;
    while(q--){
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            printf("0\n");
            continue;
        }
        int minl=N2,maxr=0;
        for(int i=0;i<t1.size();i++){
            t1_s[i+1]=(t1_s[i]*base+t1[i])%mod;
            t2_s[i+1]=(t2_s[i]*base+t2[i])%mod;
            if(t1[i]!=t2[i]){
                minl=min(minl,i);
                maxr=i;
            }
        }
        ans=0;
        for(int i=1;i<=n;i++){
            for(int l=0,r=len[i]-1;r<t1.size();l++,r++){
                if(l<=minl && r>=maxr && __hash(t1_s,l+1,r+1)==s1[i] && __hash(t2_s,l+1,r+1)==s2[i])  ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}