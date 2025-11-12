#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MOD=998244353;
int n,a[5005],dt[5005];
long long ans=0;
void f(int pos,int sum,int mx,int cnt){
    if(cnt>=3&&sum>2*mx){
        /*//cout<<pos<<" "<<sum<<" "<<mx<<" "<<cnt<<endl;
        ans++;
        ans%=MOD;
        ans+=(pos-1)*pos/2;
        ans%=MOD;
        return ;*/
        ans++;
        ans%=MOD;
    }
    if(sum+dt[pos-1]<=2*mx){
        return ;
    }
    if(cnt+pos-1<3) return ;
    for(int i=pos-1;i>=1;i--){
        f(i,sum+a[i],max(mx,a[i]),cnt+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool flag=false;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1){
            flag=true;
        }
    }
    if(!flag){
        cout<<(n-1)*(n-2)/2;
    }else{
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            dt[i]=dt[i-1]+a[i];
        }
        for(int i=n;i>=1;i--){
            f(i,a[i],a[i],1);
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
