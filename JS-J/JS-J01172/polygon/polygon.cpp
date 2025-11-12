#include<bits/stdc++.h>
using namespace std;
int a[5000+10];
long long n,cnt=0,ans=0;
int maxn=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt+=a[i];
        maxn=max(maxn,a[i]);
    }
    if(cnt>maxn*2) ans++;
    cout<<ans<<endl;
    return 0;
}