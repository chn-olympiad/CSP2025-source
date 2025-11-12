#include <bits/stdc++.h>
#define MAXN 200003
#define MAXL 5000003
using namespace std;
int n,q;
struct TMP{
    unsigned long long hash1,hash2,poshash;
    int beg,end,len; int val;
}s[MAXN];
string s1,s2;
const unsigned long long B=31;
unsigned long long b[MAXL];
void init(){
    b[0]=1;
    for (int i=1;i<=MAXL-2;i++){
        b[i]=b[i-1]*B;
    }
    return;
}
string t1,t2;
unsigned long long h1[MAXL],h2[MAXL];
int main(){
    // freopen("replace2.in","r",stdin);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    init();
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>s1>>s2;
        int l=s1.length(); int cntdf=0;
        for (int j=0;j<l;j++){
            s[i].hash1=s[i].hash1*B+(unsigned long long)s1[j];
            s[i].hash2=s[i].hash2*B+(unsigned long long)s2[j];
            if (s1[j]!=s2[j]){
                if (cntdf==0) s[i].beg=j;
                s[i].end=j;
                s[i].poshash=s[i].poshash*b[cntdf]+(unsigned long long)(s1[j]-s2[j]);
                cntdf++;
            }
        }
        s[i].val=cntdf; s[i].len=l;
    }
    // for (int i=1;i<=n;i++){
    //     cerr<<"s:"<<s[i].hash1<<' '<<s[i].hash2<<' '<<s[i].poshash<<'\n';
    // }
    while (q--){
        cin>>t1>>t2;
        int l=t1.length(),l2=t2.length();
        if (l!=l2){
            cout<<0<<'\n';
            continue;
        }
        int cntdf=0,beg=0,end=0; unsigned long long poshash=0;
        for (int i=0;i<l;i++){
            h1[i]=h1[(i==0)?0:(i-1)]*B+(unsigned long long)t1[i];
            h2[i]=h2[(i==0)?0:(i-1)]*B+(unsigned long long)t2[i];
            if (t1[i]!=t2[i]){
                if (cntdf==0) beg=i;
                end=i;
                poshash=poshash*b[cntdf]+(unsigned long long)(t1[i]-t2[i]);
                cntdf++;
            }
        }
        // cerr<<"t:"<<h1[l-1]<<' '<<h2[l-1]<<' '<<poshash<<'\n';
        // cerr<<"h1:";
        // for (int i=0;i<l;i++) cerr<<h1[i]<<' '; cerr<<'\n';
        int ans=0;
        for (int i=1;i<=n;i++){
            if (s[i].val!=cntdf) continue;
            if (s[i].end-s[i].beg!=end-beg) continue;
            if (s[i].poshash!=poshash) continue;
            int lf=beg-s[i].beg-1; int ri=lf+s[i].len;
            // cerr<<"ok i="<<i<<'\n';
            // cerr<<"lf:"<<lf<<' '<<"ri:"<<ri<<'\n';
            // cerr<<h1[ri]-((lf==-1)?0:(h1[lf]*b[ri-lf]))<<' '<<h2[ri]-((lf==-1)?0:(h2[lf]*b[ri-lf]))<<'\n';
            if (s[i].hash1==h1[ri]-((lf==-1)?0:(h1[lf]*b[ri-lf])) && s[i].hash2==h2[ri]-((lf==-1)?0:(h2[lf]*b[ri-lf]))){
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}