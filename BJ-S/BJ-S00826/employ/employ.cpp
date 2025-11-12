#include<bits/stdc++.h>
using namespace std;
char s[510],a[510];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)cin>>a[i],if(a[i]>n)ans++;
    if(ans<m)cout<<0;
    else{
        int x=1;
        for(int i=1;i<=n;i++)x*=i;
        cout<<x;
    }
return 0;
}