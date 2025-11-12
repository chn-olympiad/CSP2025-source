#include<bits/stdc++.h>
using namespace std;
int n,a[500005],ans;
bool flag;
long long k,sum;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(!flag){
            sum=a[i];
            flag=1;
        }else sum^=a[i];
        if(sum==k){
            ans++;
            flag=0;
        }
    }cout<<ans;
    return 0;
}
