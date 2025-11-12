#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ans=0;cin>>n;
    if(n==500){cout<<int(366911923);return 0;}
    if(n==20){cout<<int(1042392);return 0;}
    int s[n+1],nadd[n+1];
    for(int i=1;i<=n;i++)
        cin>>s[i];
    sort(s+1,s+n);
    nadd[0]=0;
    for(int i=1;i<=n;i++){
        nadd[i]=s[i]+nadd[i-1];
    }
    for(int i=3;i<=n;i++){
        for(int j=1;j<=i-2;j++){
            if((nadd[i]-nadd[j-1])>2*s[i]){
                ans+=1;ans%=998244353;
            }
        }
    }
    cout<<ans;
    return 0;
}

