 #include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+10;
LL n,k,a[N],ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        LL sum=0;
        for(int j=i;j<=n;j++){
            sum^=a[j];
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
