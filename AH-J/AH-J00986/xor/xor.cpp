#include<bits/stdc++.h>
using namespace std;
long long n,k,m,ans=0;
long long a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long l=1;l<=n;l++){
        for(long long r=l;r<=n;r++){
            m=a[l];
            for(long long q=l+1;q<=r;q++){
                m=m^a[q];
            }
            if(m==k){
                ans++;
                l=r+1;
                r=l;
            }
        }
    }
    cout<<ans;
    return 0;
}
