#include<bits/stdc++.h>
using namespace std;
int a[500005],d[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d[i]=a[i-1]^a[i];
    }
    if(k==0){
        int cnt=0,sum=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                cnt++;
            }
            if(a[i]==1){
                sum++;
            }
        }
        if(sum+cnt==n){
            cout<<cnt+sum/2;
            return 0;
        }

    }
    if(k==1){
        int cnt=0,sum=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                cnt++;
            }
            if(a[i]==1){
                sum++;
            }
        }
        if(sum+cnt==n){
            cout<<sum;
            return 0;
        }
    }
    return 0;
}
