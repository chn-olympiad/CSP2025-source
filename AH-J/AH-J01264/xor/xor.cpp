#include<bits/stdc++.h>
using namespace std;
long long n,k;
const int N=5e5+91;
long long s;
long long ks[N];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>ks[i];
    }
    for(long long i=1;i<=n;i++){
        for(long long j=i;j<=n;j++){
            long long glax=ks[i];
            for(long long u=i+1;u<=j;u++){
                glax^=ks[u];
            }
            if(glax==k){
                s++;
                i=j;
                break;
            }
        }
    }
    cout<<s;
    return 0;
}
