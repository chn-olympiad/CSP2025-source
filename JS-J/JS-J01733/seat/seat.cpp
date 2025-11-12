#include<bits/stdc++.h>
using namespace std;
int a[120],n,m;
int sum[101];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i],sum[a[i]]++;
    int ans=0;
    for(int i=100;i>=a[1];i--) ans+=sum[i];
    cout<<(ans+n-1)/n<<" ";
    int k=ans+n-1;
    k/=n;
    if(k%2==1) cout<<ans-(k-1)*n<<endl;
    else cout<<k*n-ans+1<<endl;
    return 0;
}
