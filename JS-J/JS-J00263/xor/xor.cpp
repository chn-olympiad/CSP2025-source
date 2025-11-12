#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010],dp1[500010],dp2[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp2[i]=a[i];
    }
    memset(dp1,0,sizeof(dp1));
    for(int i=1;i<=n;i++){
        if(dp2[i]==k){
            dp2[i]=-1;
            dp1[i]=dp1[i-1]+1;
        }
        else{
            int c=abs(k-dp2[i]);
            if(dp2[i-1]!=-1&&(abs(k-dp2[i-1]^dp2[i])<c||dp2[i-1]^dp2[i]==k)) dp2[i]=dp2[i-1]^dp2[i];
            /*
            if(dp2[i-1]==-1);
            else dp2[i]=dp2[i-1]^dp2[i];
            */
            if(dp2[i]==k){
                dp2[i]=-1;
                dp1[i]=dp1[i-1]+1;
            }
            else dp1[i]=dp1[i-1];
        }
    }
    cout<<dp1[n];
    return 0;
}
