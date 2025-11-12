#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5050],ans,flag,num;
bool p=true;
const int MOD=998244353;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)p=false;
    }
    if(p){
        for(int i=1;i<=n-2;i++){
            num=0;
            for(int j=1;j<=i;j++){
                num=num+num+j;
            }
            ans+=num;
        }
        cout<<ans<<endl;
        return 0;
    }
    sort(a+1,a+n+1);
    flag=n;
    for(int i=n;i>=3;i--){
        int sum=0;
        for(int j=1;j<n;j++){
            sum+=a[j];
        }
        if(sum>a[i]){
            flag=i;
            num=sum;
            ans++;
            break;
        }
    }
    for(int i=1;i<flag-2;i++){
        int k=num;
        for(int j=1;j<=flag-1;j++){
            if(num-a[j]<a[flag]){
                num-=a[j-1];
                ans+=(j-1);
                ans%=MOD;
                break;
            }
        }
        if(num==k)ans+=flag-1;
        if(num<=a[flag])break;
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
