#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],ans,sum,b[100005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=2 and k==0){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==k and b[i]==0){ans++;continue;}
        for(int j=i;j<=n;j++){
            sum=0;
            for(int l=i;l<=j;l++){
                if(b[l])break;
                sum^=a[l];
            }
            if(sum==k){
                ans++;
                for(int x=i;x<=j;x++)b[x]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
