#include<bits/stdc++.h>
using namespace std;
int b[100005];
int main(){
    int n,k;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    if(k==1){
        cout<<0;
    }
    return 0;
}
