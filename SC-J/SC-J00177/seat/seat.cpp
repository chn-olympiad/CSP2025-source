#include<bits/stdc++.h>
using namespace std;

vector<int> res;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a),res.push_back(a);
    int qwq=res[0];
    sort(res.begin(),res.end());
    int pos=res.end()-lower_bound(res.begin(),res.end(),qwq)-1;
    printf("%d ",pos/n+1);
    if((pos/n+1)&1) printf("%d ",pos%n+1);
    else printf("%d ",n-pos%n);
    return 0;
}