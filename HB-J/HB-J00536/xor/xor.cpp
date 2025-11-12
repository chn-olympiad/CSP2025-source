#include<bits/stdc++.h>
using namespace std;
int n,a[500005],tmp,ans,k;
long long sm;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        ans=0;
        for(int j=i;j>tmp;j--){
            ans^=a[j];
            if(ans==k){
                sm++;
                // cout<<sm<<" "<<j<<" "<<i<<endl;
                tmp=i;
            }
        }
    }
    cout<<sm;
}