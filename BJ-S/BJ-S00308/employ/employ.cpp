#include<bits/stdc++.h>
using namespace std;
int n,m,c[500];
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++) cin>>c[i];
    int a=1,b=1;
    for(int i=n;i>n-m;i--) a*=i;
    for(int i=m;i>0;i--) b*=i;
    int ans=a/b;
    cout<<ans<<endl;
}
