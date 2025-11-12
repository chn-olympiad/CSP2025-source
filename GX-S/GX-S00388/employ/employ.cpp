#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,a,t=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a==0){
            t=1;
        }
    }
    if(t==0){
        cout<<n;
    }
    return 0;
}
