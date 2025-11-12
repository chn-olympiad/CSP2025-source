#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
using ull=unsigned long long;
using ll=long long;
const int N=2e5+5;
const int M=2.5e6+5;
const int bas=19260817;
const int mod1=998244353,mod2=1e9+7;
const ull nbs=1e9+9;
int n,m;
int nel[M];
ull bs1[M],bs2[M];
gp_hash_table<ull,int> ma;
int h11[M<<1],h12[M<<1],h21[M<<1],h22[M<<1];
char nc[M<<1];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&m);
    bs1[0]=bs2[0]=1;
    const int lim=2.5e6;
    for(int i=1;i<=lim;++i){
        bs1[i]=bs1[i-1]*bas%mod1;
    }
    for(int i=1;i<=lim;++i){
        bs2[i]=bs2[i-1]*bas%mod2;
    }
    for(int i=1;i<=n;++i){
        char c=getchar();
        int len=0;
        while(c<'a'||'z'<c)c=getchar();
        int h11=0,h12=0;
        while('a'<=c&&c<='z'){
            ++len;
            h11=(1ll*h11*bas+c)%mod1;
            h12=(1ll*h12*bas+c)%mod2;
            c=getchar();
        }
        nel[len]=len;
        while(c<'a'||'z'<c)c=getchar();
        int h21=0,h22=0;
        while('a'<=c&&c<='z'){
            h21=(1ll*h21*bas+c)%mod1;
            h22=(1ll*h22*bas+c)%mod2;
            c=getchar();
        }
        ull hh=((h11*nbs+h12)*nbs+h21)*nbs+h22;
        ma[hh]++;
    }
    nel[lim+1]=lim+1;
    for(int i=lim;i;--i){
        if(!nel[i])nel[i]=nel[i+1];
    }
    while(m--){
        char c=getchar();
        int len=0;
        while(c<'a'||'z'<c)c=getchar();
        while('a'<=c&&c<='z'){
            ++len;
            nc[len]=c;
            h11[len]=(1ll*h11[len-1]*bas+c)%mod1;
            h12[len]=(1ll*h12[len-1]*bas+c)%mod2;
            c=getchar();
        }
        int llen=len;
        len=0;
        int la=0,be=0;
        while(c<'a'||'z'<c)c=getchar();
        while('a'<=c&&c<='z'){
            ++len;
            if(c!=nc[len]){
                la=len;
                if(!be)be=len;
            }
            h21[len]=(1ll*h21[len-1]*bas+c)%mod1;
            h22[len]=(1ll*h22[len-1]*bas+c)%mod2;
            c=getchar();
        }
        if(llen!=len){
            printf("0\n");
            continue;
        }
        ll ans=0;
        for(int i=1;i<=be;++i){
            int mil=nel[la-i+1];
            while(mil!=lim+1){
                if(i+mil-1>len)break;
                int r=i+mil-1;
                ull hh=(((h11[r]-h11[i-1]*bs1[mil]%mod1+mod1)%mod1*nbs+(h12[r]-h12[i-1]*bs2[mil]%mod2+mod2)%mod2)*nbs+(h21[r]-h21[i-1]*bs1[mil]%mod1+mod1)%mod1)*nbs+(h22[r]-h22[i-1]*bs2[mil]%mod2+mod2)%mod2;
                if(ma.find(hh)!=ma.end())ans+=ma[hh];
                mil=nel[mil+1];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
g++ -o replace replace.cpp -O2 -std=c++14 && time ./replace
*/
