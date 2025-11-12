#include<bits/stdc++.h>
using namespace std;
int n,l[5010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>l[i];
    }
    if(l[0]>l[1]+l[2]&&l[1]>l[0]+l[2]&&l[2]>l[0]+l[1]){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
