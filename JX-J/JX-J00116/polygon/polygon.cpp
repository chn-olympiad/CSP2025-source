#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int ans,n,a[maxn];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==3&&a[1]+a[2]+a[3]<max(a[1],max(a[2],a[3]))*2)
            cout<<1;
    else if(n==3)
        cout<<0;
	return 0;
}
