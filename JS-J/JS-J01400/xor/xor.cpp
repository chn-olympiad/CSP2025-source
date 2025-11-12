#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,cnt;
int a[500005];
bool flag=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cnt=a[1];
    if(cnt==k){
        ans++;
        flag=1;
    }
    for(int i=2;i<=n;i++){
        if(flag==0){
            if(cnt==a[i])cnt=0;
            else cnt=1;
        }
        if(flag==1){
            cnt=a[i];
            flag=0;
        }
        if(cnt==k){
            ans++;
            flag=1;
        }
    }
    cout<<ans;
    return 0;
}
