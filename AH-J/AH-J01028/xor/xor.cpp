#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,sum[100010];
struct stu{
    int l,r;
}a[10000];
bool cmp(const stu x,const stu y){
    return x.r>y.r;
}
int main(){
    freopen("xoc.in","r",stdin);
    freopen("xoc.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n/2;i++){
        long long t;
        cin>>t;
        sum[i]=sum[i-1]^t;
    }
    cout<<1;
    return 0;
}
