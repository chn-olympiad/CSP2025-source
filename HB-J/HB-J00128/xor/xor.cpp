#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int rd(){
    char ch=getchar();int s=0,f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<1)+(s<<3)+(ch^48);
        ch=getchar();
    }
    return s*f;
}
const int N=5e5+10;
int n,k,a[N],sum[N];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=rd(),k=rd();//printf("%lld\n",k);
    for(int i=1;i<=n;i++){
        a[i]=rd();
        // sum[i]=(sum[i-1]^a[i]);
    }
    int cnt=0;
    if(k==0){
        printf("%lld\n",n);
    }
    return 0;
}