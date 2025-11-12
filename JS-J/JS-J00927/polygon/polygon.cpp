#include<bits/stdc++.h>
using namespace std;

int n,sum,ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    if(sum>2*a[n-1]){
        ans=n-2;
    }
    else ans=n-3;
    cout<<ans;
    return 0;
}


