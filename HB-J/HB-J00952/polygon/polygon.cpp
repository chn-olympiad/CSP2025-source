#include <iostream>

using namespace std;
int a[100010];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=2){
        cout<<0;
    }
    if(n==3){
        int maxn=max(a[1],max(a[2],a[3]));
        if(a[1]+a[2]+a[3]>maxn)cout<<1;
        else cout<<0;
    }
    return 0;
}
