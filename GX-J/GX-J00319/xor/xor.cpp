#include <bits/stdc++.h>

using namespace std;

long long n,k;
long long a[500010];
long long ans;
long long s[500010];

int main()
{
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=(s[i-1]^a[i]);
    }
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if((s[j]^s[i])==k){
                ans++;
                i=j;
            }
        }
    }
    cout<<ans;
    return 0;
}
