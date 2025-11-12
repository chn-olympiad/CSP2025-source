#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,k;
long long qz[500005],a[500005],cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        qz[i]=a[i]^qz[i-1];
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((qz[j]^qz[i-1])==k){
                cnt++;
                i=j+1;
                break;
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
