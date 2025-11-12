#include<bits/stdc++.h>
using namespace std;
long long a[5005],ans,s[500005],mx,n,f[5005],t[500005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    f[a[1]]++,f[a[2]]++,s[a[1]+a[2]]++;
    mx=a[1]+a[2];
    for(int i=3;i<=n;i++){
        for(long long j=1;j<=mx;j++)
            if(j>a[i]) ans+=s[j];
        for(long long j=0;j<=mx;j++){
            if(j==0) f[a[i]]++;
            else{
                if(s[j]!=0){
                    s[j+a[i]]=s[j+a[i]]+s[j]-t[j],t[j+a[i]]=s[j+a[i]];
                }
                if(f[j]!=0){
                    if(j!=a[i]) s[j+a[i]]+=f[j],t[j+a[i]]=f[j];
                    else s[j+a[i]]+=f[j]-1,t[j+a[i]]=s[j+a[i]];
                }
            }
        }
        memset(t,0,sizeof(t));
        mx+=a[i];
    }
    cout<<ans;
    return 0;
}
