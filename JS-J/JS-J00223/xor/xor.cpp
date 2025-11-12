#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int a[N],sum[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    int i=1,j=1,ans=0;
    while(i<=n){
        bool f=0;
        while(j<=n){
            int t=sum[j]^sum[i-1];
            if(t==k){
                ans++;
                f=1;
                break;
            }
            j++;
        }
        if(f){
            j++;
            i=j;
        }
        else{
            i++;
            j=i;
        }
    }
    cout<<ans;
    return 0;
}
