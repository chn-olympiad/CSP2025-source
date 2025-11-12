#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int a[100001],cnt,n;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(n==3){
        if(a[1]+a[2]>a[3]) cout<<1;
        else cout<<0;
    }
    else{
        for(int i=4;i<=n;i++){
            long long sum=1,k;
            if(i<=n/2) k=i;
            else k=n-i;
            for(int j=n;j>n-k;j--) sum=sum*j%N;
            for(int j=1;j<=k;j++) sum/=j;
            cnt+=sum;
            cnt%=N;
        }
        cout<<cnt;
    }
    return 0;
}
