
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n,k;
int sum[maxn];
struct node {
    int l,r;
};
vector <node> ans;
int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    m[0]=1;
    for(int i=1;i<=n;++i) {
        int num=0;
        scanf("%lld",&num);
        sum[i]=sum[i-1]^num;
    }
    for(int r=1;r<=n;++r) {
        for(int l=r;l>=1;--l) {
            if((sum[r]^sum[l-1])==k) {
                ans.push_back((node){l,r});
                break;
            }
        }
    }
    int end=0,res=0;
    for(int i=0;i<ans.size();++i) {
        if(ans[i].l<=end) continue;
        end=ans[i].r;
        ++res;
    } printf("%lld\n",res);
    return 0;
}
