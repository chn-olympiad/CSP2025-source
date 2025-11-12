#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
    long long sum1 = 1,sum =0 ;
    for (int j=1;j<=n-m;j++){
        sum1 = 1;
        for (int i=m;i<=n;i++){
            sum1 *= i;
            sum1 %= mod;
        }
        sum += sum1;
        sum %= mod;
    }
    cout<<sum;
    return 0;
}
