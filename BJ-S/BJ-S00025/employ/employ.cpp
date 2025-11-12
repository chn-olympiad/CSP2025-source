#include<bits/stdc++.h>
using namespace std;
int ans=0,n,m,c[1000010],a[1000010];
char s[1000010];
const int P=1e9+7;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){scanf("%d",&c[i]);a[i]=i;}
    do{
        int notpass=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0'||notpass>=c[a[i]]) notpass++;
        }
        if(n-notpass>=m) ans=(ans+1)%P;
    }while(next_permutation(a+1,a+n+1));
    printf("%d",ans);
    return 0;
}