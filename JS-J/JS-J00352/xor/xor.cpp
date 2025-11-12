#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int k;
    cin>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            long long sum=0;
            for(int h=i;h<=j;h++){
                sum^=a[h];
            }
            if(sum==k){
                ans++;
                i=j;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
