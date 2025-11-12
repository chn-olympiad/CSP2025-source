#include<bits/stdc++.h>
using namespace std;
// inline long long read(){
//     long long x=0,w=0;
//     char c=0;
//     while(c<'0'||c>'9'){
//         w|=c=='-';
//         c=getchar();
//     }
//     while(c>='0'&&c<='9'){
//         x=(x<<3)+(x<<1)+(c^48);
//         c=getchar();
//     }
//     return w?-x:x;
// }
const long long mod=998244353;
int n,m;
char s[550];
int c[550];
int flag=1;
long long ans,cnt,cntc,cnt0;
int p[550];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
        if(s[i]==0){
            flag=0;
            cnt0++;
        }
    }
    if(n<=11){
        cnt=1;
        for(int i=1;i<=n;i++){
            cnt=cnt*i;
            p[i]=i;
        }
        for(int i=1;i<=cnt;i++){
            if(i!=1){
                next_permutation(p+1,p+n+1);
            }
            cntc=0;
            for(int j=1;j<=n;j++){
                if(s[j]=='0'||cntc>=c[p[j]]){
                    cntc++;
                }
            }
            if(cntc<=n-m){
                ans++;
            }
        }
        printf("%lld",ans);
    }
    else if(flag){
        ans=1;
        for(int i=1;i<=n;i++){
            ans=ans*i%mod;
        }
        printf("%lld",ans);
    }
    else if(n-m<cnt0){
        printf("0");
    }
    else if(m==1){

    }
    return 0;
}
