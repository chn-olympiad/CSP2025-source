#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,sum=0,maxn=-1,ans=0;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
    if(n==3){
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(a[i]>maxn)maxn=a[i];
        }
        if(sum>maxn*2)cout<<1;
        else cout<<0;
        return 0;
    }
    for(int j=3;j<=n;j++){
        for(int i=0;i<n;i++){
            sum=0;
            for(int h=i;h<=i+j;h++){
                sum+=a[h];
                if(a[h]>maxn)maxn=a[h];
            }
            if(sum>maxn*2)ans++;
        }
    }
    cout<<ans;
    return 0;
}
