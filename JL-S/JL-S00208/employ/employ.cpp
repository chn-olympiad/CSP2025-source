#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
inline ll read(){
    ll num=0,sign=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        sign=ch=='-'?-1:1,ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
    }
    return sign>0?num:-num;
}
ll n,m,ans;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lldlld",&n,&m);
    for(int i=n-1;i>=1;i--){
        ans+=i;
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
