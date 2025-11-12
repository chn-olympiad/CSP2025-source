#include<bits/stdc++.h>
using namespace std;
long long n,s;
int a[100005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n-2;i++)
    {
        s+=i;
    }
    cout<<s;
    return 0;
}
