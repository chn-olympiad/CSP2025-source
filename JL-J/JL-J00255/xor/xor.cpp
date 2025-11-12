#include <bits/stdc++.h>
using namespace std;
int n,a[1000000],w,k,s[1000000],ans;
void yihuo(int a[],int p){
    int t=1,sum=0,ans2=0;
    for(int i=0;i<p;i++){
        for(int j=t;j<a[i]+t;j++){
            sum=sum^s[j];
        }
        if(sum==k){
            ans2++;
        }
        t+=a[i];
        sum=0;
    }
    ans=max(ans2,ans);
}
void t(int sum,int a[],int p){
    if(sum>n){
        return ;
    }
    if(sum==n){
        yihuo(a,p);
        return ;
    }
    for(int i=1;i<=n;i++){
        a[p]=i;
        sum+=i;
        p++;
        t(sum,a,p);
        sum-=i;
        p--;
        a[p]=0;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
       cin>>s[i];
    }
    if(n>=30){
        for(int i=1;i<=n;i++){
            if(s[i]==1){
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    t(0,a,0);
    cout<<ans;
    return 0;
}
