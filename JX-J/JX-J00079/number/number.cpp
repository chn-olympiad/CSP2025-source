#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
ll n,a[maxn],cnt;
char s[maxn];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if((ll)s[i]<=57&&(ll)s[i]>=48){
            a[++cnt]=(ll)s[i]-48;
        }
    }
    sort(a+1,a+cnt+1);
    for(int i=cnt;i>=1;i--){
        printf("%lld",a[i]);
    }
    printf("\n");
    return 0;
}
