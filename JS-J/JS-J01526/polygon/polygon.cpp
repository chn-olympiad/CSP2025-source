#include<bits/stdc++.h>
using namespace std;
int n,a[10000];
long long maxx,may;
int sum;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<3)cout<<0;
    if(n==3){
       for(int i=1;i<=n;i++)maxx+=a[i];
       sort(a+1,a+n+1);
       may=a[n];
       if(maxx>=2*may)cout<<1;
       else cout<<0;
    }
    if(n>3)for(int i=3;i<=n;i++)for(int j=1;j<=i;j++)if(max(max(a[j],a[j+1]),a[j+2])*2<=a[j]+a[j+1]+a[j+2])sum++;  cout<<sum;
    return 0;
}
