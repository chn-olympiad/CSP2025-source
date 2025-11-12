#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD=998244353;
int n,m;
string s;
int c[505];
bool pd=0;
int ans10=0;
int sx[505];
int fst;

inline void chk(){
    int fq=0;
    int cg=0;
    for (int i=1;i<=n;i++){
        if (s[i]=='0' or fq>=c[sx[i]]){
            fq++;
        }
        else{
            cg++;
            if (cg>=m){
                i=n+1;
            }
        }
    }
    if (cg>=m){
        ans10++;
        ans10%=MOD;
    }
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m;
    cin>>s;
    s=' '+s;
    for (int i=1;i<=n;i++){
        cin>>c[i];
    }
    for (int i=1;i<=n;i++){
        if (s[i]!='1'){
            pd=1;
            i=n+1;
        }
    }
    if (pd==0 or m==n){
        //answer is n!
        int as=1;
        for (int i=2;i<=n;i++){
            as=as*i;
            as=as%MOD;
        }
        cout<<as<<"\n";
        return 0;
    }
    if (n<=18){
        for (int i=1;i<=n;i++){
            sx[i]=i;
        }
        do{
            chk();
        }while (next_permutation(sx+1,sx+n+1));
        cout<<ans10<<"\n";
        return 0;
    }
    if (m==1){
        for (int i=1;i<=n;i++){
            if (s[i]!='0'){
                fst=i;
                i=n+1;
            }
        }
        int cnt=0;
        for (int i=1;i<=n;i++){
            if (c[i]>=fst){
                cnt++;
            }
        }
        int jc=1;
        for (int i=2;i<n;i++){
            jc*=i;
            jc%=MOD;
        }
        int aaa=jc*cnt%MOD;
        cout<<aaa<<"\n";
        return 0;
    }
    return 0;
}