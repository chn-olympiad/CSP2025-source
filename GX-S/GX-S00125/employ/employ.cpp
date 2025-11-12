#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,a[501],x;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;//cin>>s;x=n;
    //for(int i=0;i<n;i++){
     //   cin>>a[i];if(a[i]<=0)x--;
    //}n=min(n,x+1);
    for(long long i=2;i<=n;i++){
        ans*=i;ans%=998244353;
    }cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
