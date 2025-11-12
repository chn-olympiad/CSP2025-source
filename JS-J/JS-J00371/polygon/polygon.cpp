#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,cnt=0;
long long a[5005]={0};
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n-2;i++){
        sum=a[i]+a[i+1];
        for(long long j=i+2;j<=n;j++){
            sum+=a[j];
            if(a[j]*2<sum){
                cnt++;
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
