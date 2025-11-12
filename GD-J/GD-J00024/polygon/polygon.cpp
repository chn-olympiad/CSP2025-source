#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int l[100005],k,n;
    cin>>n;
    int maxx=0,s=0;
    for(int i=0;i<n;i++){
        cin>>l[i];
        maxx=max(maxx,l[i]);

    }
    int dp[100005];
    sort(l,l+n);

    cout<<n+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

