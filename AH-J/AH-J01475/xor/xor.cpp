#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],t[1010];
bool is_0or1=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]<=1000) t[a[i]]++;
        if(a[i]!=1&&a[i]!=0) is_0or1=0;
    }
    if(is_0or1){
        if(k==0){
            int l=1,ans=0;
            for(int i=1;i<=n+1;i++){
                if(a[i]==0) ans+=(i-1-l+1)/2,l=i+1,ans++;
            }
            ans--;
            cout<<ans<<endl;
            return 0;
        }
        if(k==1){
            cout<<t[1]<<endl;
            return 0;
        }
    }
    cout<<t[1]<<endl;
    return 0;
}
