#include<bits/stdc++.h>
using namespace std;
int a[10000001],maxn=0;
int ans;
int n,t;
int need;
int db(int h){
    int cnt=0;
    for(int i=h;h<=n;h++)cnt+=a[h];
    return cnt;
}
void fs(int y,int now){
    if(now>need){
        int g=pow(2,n-y-1)%998244353;
        ans+=g;ans%=998244353;
        return;
    }
    for(int j=y+1;j<=n;j++){
        if((need-now)<db(j))fs(j,now+a[j]);
        else return;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin >>n;
    for(int i=1;i<=n;i++)cin>>a[i],maxn=max(maxn,a[i]);
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(a[i]<a[j])t=a[i],a[i]=a[j],a[j]=t;
    int now=0;
    if(maxn==1){cout<<(n-1)*(n-2)/2;return 0;}

    else for(int i=1;i<=n-2;i++){need=a[i];fs(i,0);}

    cout<<ans;
    return 0;
}
