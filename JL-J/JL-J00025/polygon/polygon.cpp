#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int n,ans=0;
int a[100010];
const int mod=998244353;
void g(int x){
    if(x==0)
        return ;
    g(x/2);
    cout<<x%2;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<(int)pow(2,n);i++){
        int cnt=0;
        int maxv=-1;
        int sum=0;
        int l=i,x=1;
        while(l){
            if(l&1==1){
                cnt+=a[x];
                maxv=max(maxv,a[x]);
                sum++;
            }
            l=(l>>1);
            x++;
        }
        if(cnt>maxv*2&&sum>=3)
            ans++;
        //g(i);
        //cout<<' '<<ans<<' '<<cnt<<' '<<maxv;
        //cout<<endl;
    }
    cout<<ans;
    return 0;
}
