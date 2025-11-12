//Luogu: 1116515 Could you subscribe me?
#include <bits/stdc++.h>
using namespace std;
/*
走过路过没遇过，回头转头还是错，
你我不曾感受过，相撞在街口，相撞在街口。
*/
const int MOD=998244353;
char s[505];
int n,m,a[505],b[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d%s",&n,&m,s+1);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]),a[i]=i;
    int ans=0;
    do{
        int p=0,c=0;
        for(int i=1;i<=n;i++){
            if(c<b[a[i]]&&s[i]=='1') p++;
            else c++;
        }
        ans+=(p>=m);
        if(ans>=MOD) ans-=MOD;
    }while(next_permutation(a+1,a+n+1));
    printf("%d",ans);
    return 0;
}