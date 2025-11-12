#include<bits/stdc++.h>
using namespace std;
long long int k,ans=0,a[500010],b[500010],n;
long long int yh(long long int x,long long int y){
    int wei[25]={0},zz=0;
    long long int ans=0;
    while(x>0||y>0){
        if(x%2+y%2==1)wei[zz]=1;
        x/=2;
        y/=2;
        zz++;
    }
    for(int i=0;i<zz;i++)ans+=wei[i]*pow(2,i);
    return ans;
}
void check(int left,int right){
    for(int i=left;i<=right;i++){
        for(int j=left;j<=i;j++){
            if(yh(b[i],b[j])==k){
                ans++;
                check(i,right);
                return ;
            }
        }
    }
    return ;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    b[0]=0;
    for(int i=1;i<=n;i++)b[i]=yh(b[i-1],a[i-1]);
    check(0,n);
    cout<<ans;
    return 0;
}
