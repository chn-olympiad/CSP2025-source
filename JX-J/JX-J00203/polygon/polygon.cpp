#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5001];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==3){
        sort(a+1,a+n+1);
        if(a[1]+a[2]>a[3])
            cout<<1;
        else cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
