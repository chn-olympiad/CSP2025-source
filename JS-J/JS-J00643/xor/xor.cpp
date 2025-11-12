#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],sum[500010],ak,att[500010],s[500010],ans,vis[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        int ali=0;
        for(int j=1;j<=n-i+1;j++){
            if((s[j+i-1]-s[j-1])>0)continue;
            ali++;
            if((sum[j+i-1]^sum[j-1])==k){
                ans++;
                att[j+i-1]--;
                att[j-1]++;
                j+=i-1;
            }
        }
        if(ali==0)break;
        for(int i=1;i<=n;i++){
            vis[i]=vis[i-1]+att[i-1];
            s[i]=s[i-1]+vis[i];
        }
    }
    cout<<ans;
    return 0;
}
