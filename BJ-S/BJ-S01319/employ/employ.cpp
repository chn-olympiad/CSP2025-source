#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],a[505],b[505],ans,fl=1;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++)cin>>c[i];
    a[0]='1'-s[0];
    for(int i=1;i<n;i++){
        a[i]=a[i-1]-(s[i]-'1');
        if(a[i]=='0')fl=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]<=c[j]){
                b[i]++;
            }
        }
    }
    ans=1;
    if(fl){
        for(int i=1;i<=n;i++){
            ans*=i%998244353;
            ans%=998244353;
        }
    }
    cout<<ans;
    return 0;
}
