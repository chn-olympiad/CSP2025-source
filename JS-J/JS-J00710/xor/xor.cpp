#include<bits/stdc++.h>
using namespace std;
int n,k,ans,p=0;
int a[500010],s[500010];
int f[500010][2];
int mp[1000010];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[++p];
        if(a[p]!=0){
            s[p]=s[p-1]^a[p];
        }
        else{
            p--;
        }
    }
    n=p;
    if(n<=1000){
        for(int i=1;i<=n;i++){
            f[i][0]=max({f[i][0],f[i-1][0],f[i-1][1]});
            for(int j=0;j<=i;j++){
                if((s[i]^s[max(j-1,0)])==k){
                    f[i][1]=max({f[i][1],f[j][1],f[j][0]+1});
                }
            }
            ans=max({ans,f[i][0],f[i][1]});
        }
        cout<<ans<<"\n";
    }else{
        for(int i=1;i<=n;i++){
            f[i][0]=max({f[i][0],f[i-1][0],f[i-1][1]});
            f[i][1]=max(f[i][1],mp[s[i]^k]);
            if(s[i]==k) f[i][1]=max(f[i][1],1);
            if(a[i]==k) f[i][1]=max(f[i][1],f[i][0]+1);
            mp[s[i-1]]=max({mp[s[i]],f[i][1],f[i][0]+1});
            ans=max({ans,f[i][0],f[i][1]});
        }
        cout<<ans<<"\n";
    }
    return 0;
} 