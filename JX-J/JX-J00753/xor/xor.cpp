#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int sum[N];
int n,m,ma=0;
long long ans=0;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j>ma;j--){
            int now=sum[i]^sum[j-1];
            if(now==m){
                ++ans;
                ma=i;
                break;
            }

        }

    }
    cout<<ans;

    return 0;
}
