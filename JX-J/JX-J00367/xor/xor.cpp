#include<bits/stdc++.h>
using namespace std;
#define LL long long
int a[500005];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int last=0,ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int t=a[i];
        for(int j=i;j>last;j--){
            if(j!=i)t^=a[j];
            if(t==k){
                last=i;
                ans++;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
