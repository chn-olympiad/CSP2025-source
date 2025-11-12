#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int t,a[maxn],ans,b[maxn],c[maxn];
int main(){
    freopen("club.in", "r", stdin);
    freopen("clud.out", "w", stdout);
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        sort(a+1,a+n+1);
        for(int i=n;i>n/2;i--)
            ans+=a[i];
        cout<<ans;
    }
    return 0;
}
