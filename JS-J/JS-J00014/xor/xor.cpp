#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n,k,ans;
ll a[N],sum;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        sum^=a[i];
        //cerr<<"i: "<<i<<" sum: "<<sum<<'\n';
        if(sum==k){
            sum=0,ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
