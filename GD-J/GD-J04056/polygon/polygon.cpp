#include<bits/stdc++.h>
using namespace std;
long long sum,s[5005];
int n,a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i = (1<<3);i<=(1<<n);i++){
        long long l = i;
        long long ans = 0;
        for(int j = 1;j<=n;j++)
            if(l%2 == 1) ans += a[j];
            l /= 2;
        }
        if(ans > 2*a[i]) sum++;
    }
    cout<<sum;
}
