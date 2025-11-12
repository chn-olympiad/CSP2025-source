#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],k,s[500005],cnt,p;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        s[i]=s[i-1]^a[i];
    }
    for(long long i=1;i<=n;i++){
        for(long long j=p+1;j<=i;j++){
            if((s[i]^s[j-1])==k){
                p=i;
                cnt++;
                break;
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
