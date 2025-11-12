#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
struct node{
    int x,step;
};
int n,k,a[N],m[N],s[N];
queue<node> q;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        s[i]=a[i]^s[i-1];
    }q.push({1,0});
    while(q.size()){
        node f=q.front();
        for(int i=f.x;i<=n;i++){
            for(int j=i;j<=n;j++){
                int sum=s[j]^s[i-1];
                if(sum==k){
                    if(f.step+1>m[j]){
                        for(int k=j;k<=n;k++) m[k]=max(f.step+1,m[k]);
                        q.push({j+1,m[j]});
                    }
                }

            }
        }q.pop();
    }printf("%lld\n",m[n]);
    return 0;
}