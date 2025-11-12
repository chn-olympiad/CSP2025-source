#include<bits/stdc++.h>
using namespace std;
int n,m,c[100005],s[100005],ans=0;
int main(){

freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);

for(int i=0;i<=n;i++){
    cin>>n>>m;
    cin>>s[i];
    if(s[i]=0)
        ans=ans;
    if(s[i]=1)
        ans++;
for(int j=0;j<=n;j++){
    cin>>c[j];
    if(ans>=c[j])
        ans=ans;
        break;
    }
}
    cout<<ans%998,244,353;
return 0;
}
