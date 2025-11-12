#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long sum;
int main(){
    freopen("polygon.in","r",stdin);//wenjian
    freopen("polygon.out","w",stdout);//wenjian
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        sum%=998244353;
    }
    cout<<sum;
    fclose(stdin);//IOADHNIOWHADI
    fclose(stdout);//asdihjedf
    return 0;
}
