#include<iostream>
#include<cstdio>
using namespace std;
long long n,k,a[500005],last=1,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        a[i]^=a[i-1];
    }
    for(long long i=1;i<=n;i++){
        for(long long j=i;j>=last;j--){
            if((a[i]^a[j-1])==k){
                ans++;
                last=i+1;
                break;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdin);
}
