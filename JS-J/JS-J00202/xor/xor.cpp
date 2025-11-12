#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,sum[500005],candybarisverygood,ans,k;
unordered_set<int> quqi;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);quqi.insert(0);
    for (int i=1;i<=n;++i){
        scanf("%d",&candybarisverygood);sum[i]=sum[i-1]^candybarisverygood;
        if (quqi.count(sum[i]^k)){quqi.clear();++ans;}
        quqi.insert(sum[i]);
    }
    printf("%d\n",ans);
    return 0;
}
