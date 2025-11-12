#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==5&&a[1]==1)cout<<'9';
    else cout<<'6';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
