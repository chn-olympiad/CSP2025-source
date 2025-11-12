#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],cnt,pos;
bool flag;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            cnt++;
            continue;
        }
        flag=0,pos=0;
        for(int j=i+1;j<=n;j++){
            if((sum[j]^sum[i-1])==k){
                flag=1;
                pos=j;
                cnt++;
                break;
            }
            if(a[j]==k) break;
        }
        if(flag) i=pos;
    }
    cout<<cnt;
}
