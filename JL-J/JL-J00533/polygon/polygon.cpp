#include<bits/stdc++.h>
using namespace std;
int n.a[5010],p,ans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p+=a[i];
    }
    sort(a+1,a+n+1);
    if(p>2*a[i])
        ans++;
    if(n<=3)
        return 0;
    cout<<ans<<endl;
    return 0;

}
