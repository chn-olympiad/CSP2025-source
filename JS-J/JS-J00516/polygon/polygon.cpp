#include <bits/stdc++.h>
using namespace std;
long long n,a[50010],maxn,s,ans;
int jc(int k){
    long long cnt=1;
    for(int i=1;i<=k;i++){
        cnt*=i;
    }
    return cnt;
}
void lesson(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(n==3){
        for(int i=1;i<=n;i++){
            s+=a[i];
        }
        if(s>2*maxn){
            cout<<1;
        }
        else cout<<0;
        return ;
    }
    if(maxn==1){
        for(int i=3;i<=n;i++){
            long long x=jc(n),y=jc(n-i),z=jc(i);
            ans+=x/y/z;
        }
        cout<<ans%998244353;
        return ;
    }

}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    lesson();
    return 0;
}
