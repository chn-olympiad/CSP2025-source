#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],xorsum[500010],t[1000010],ans;
stack<int> f;
int lowbit(int x){
    return x&(-x);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    t[0]++;
    f.push(0);
    for(int i=1;i<=n;i++){
        xorsum[i]=(xorsum[i-1]^a[i]);
        f.push(xorsum[i]);
        if(t[(xorsum[i]^k)] || a[i]==k){
            while(!f.empty()){
                t[f.top()]--;
                f.pop();
            }
            t[xorsum[i]]++;
            f.push(xorsum[i]);
            ans++;
        }
        t[xorsum[i]]++;
    }
    printf("%d\n",ans);
    return 0;
}
