#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[N]={0},vis[N]={0},cnt=0;
    cin>>n>>k;
    int cnt0=0,cnt1=0,cntn=0,cnt1p=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0)cnt0++;
        else if(a[i]==1)cnt1++;
        else cntn++;
        if(a[i]==a[i-1]&&a[i]==1&&vis[i-1]==0){
            cnt1p++;
            vis[i]=1;
        }
    }
    if(cntn==0){
        if(k==1)cout<<cnt1;
        else if(k==0&&cnt0==0)cout<<0;
        else if(k==0&&cnt0!=0)cout<<cnt0+cnt1p;
        return 0;
    }
    for(int i=2;i<=n;i++){
        a[i]=a[i-1]^a[i];
        if(a[i]==k)cnt++;
    }
    cout<<cnt;
    return 0;
}
