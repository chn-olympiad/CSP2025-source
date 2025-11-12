#include<bits/stdc++.h>
using namespace std;
int ans[2];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ans[x]++;
    }
    if(k==0){
        cout<<ans[0]+ans[1]/2;
    }
    else{
        cout<<ans[1]+ans[0]/2;
    }
    return 0;
}
