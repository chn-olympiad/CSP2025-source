#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int cnt;
bool flag=1;
bool flag2=1;
int ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) flag=0;
        if(a[i]!=1&&a[i]!=0) flag2=0;
    }
    if(flag){
        cout<<n/2<<"\n";
        return 0;
    }
    if(flag2){
        if(k==1){
            int cnt=0;
            for(int i=1;i<=n;i++) cnt+=a[i];
            cout<<cnt<<"\n";
        }
        else if(k==0){
            int cnt=0;
            for(int i=1;i<=n;i++){
                cnt+=(a[i]==0);
            }
            for(int i=1;i<=n;i++){
                if(a[i]==1&&a[i+1]==1){
                    cnt++;
                    i++;
                }
            }
            cout<<cnt<<"\n";
        }
        return 0;
    }
    int sum=a[1];
    for(int i=2;i<=n;i++){
        if(sum==k) ans++,sum=a[i+1];
        sum^=a[i];
    }
    if(sum==k) ans++;
    cout<<ans<<"\n";
    return 0;
}
//wo3 zhi1 dao4 ying1 gai1 rang4 sum-mx>mx , jiu4 shi4 yuan2 lai2 de4 sum bi4 xu1 yan2 ge2 da4 yu2 xin1 de4 max , huo4 xu3 shi4 gu4 ding4 yi4 bian1 zai4 cong2 ling4 yi4 bian1 zhao3 ? dan4 shi4 wo3 bu2 hui4.
