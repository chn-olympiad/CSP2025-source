#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    vector v;
    for(int i=0;i<n;i++){
        int j;
        cin>>j;
        v.push_back(j);
    }
    sort(v.begin(),v.end());
    if(n<3) cout<<0;
    else cout<<n+1
    return 0;
}
