#include<iostream>
#include<algorithm>
using namespace std;
int a[5005],cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(a[1]+a[2]>a[3]&&a[3]>0){
        cnt=(cnt+1)%998244353;
    }
    cout<<cnt%998244353;
    return 0;
}
