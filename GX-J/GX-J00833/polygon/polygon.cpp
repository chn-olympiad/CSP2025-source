#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int num[n+1];
    for(int i=1;i<=n;i++)
        cin>>num[i];
    sort(num+1,num+n+1);
    cout<<n;
    return 0;
}
