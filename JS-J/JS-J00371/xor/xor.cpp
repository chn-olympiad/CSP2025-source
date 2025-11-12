#include<bits/stdc++.h>
using namespace std;
long long n,k,sum=0,cnt;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        if(a[i]==k){
            cnt++;
            continue;
        }
        sum=a[i];
        for(long long j=1;i+j<=n;j++){
            sum^=a[i+j];
            if(sum==k){
                i+=j;
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
