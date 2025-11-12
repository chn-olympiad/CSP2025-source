#include<bits/stdc++.h>
using namespace std;
char s[110000];
int c[110000],ans=1,num[110000];
int main(){
    int n,m,i,j;
    freopen("employ.in","w",stdin);
    freopen("employ.out","r",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    sort(c+1,c+n+1);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i<c[j])num[i]++;
        }
        ans*=min(num[i-1]-1,num[i])%998244353;
        ans%=998244353;
    }
    printf("%d\n",ans);
    return 0;
}
