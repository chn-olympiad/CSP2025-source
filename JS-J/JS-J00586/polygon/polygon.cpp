#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans,s[5010];
vector<int> a;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    a.push_back(0);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for(int t=2;t<=n-1;t++){
        cout<<"test "<<t<<'\n';
        for(int i=1;i<=n;i++){
            int j=i+t-1;
            if(j>=n) break;
            int sum=s[j]-s[i-1];
            auto it=lower_bound(a.begin(),a.end(),sum);
            if(*it==0){
                *it=n+1;
                ans+=n-j;
            }
            else{
                auto it=lower_bound(a.begin(),a.end(),sum);
                ans+=max(0,*it-j-1);
            }
            cout<<i<<" "<<j<<" "<<max(0,*it-j-1)<<'\n';
            ans%=mod;
        }
    }
    cout<<(ans+mod)%mod<<'\n';
    return 0;
}
