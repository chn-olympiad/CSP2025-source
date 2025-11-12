#include<bits/stdc++.h>
using namespace std;
long long a,b,c,p;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>c;
    for(int i=1;i<=a;i++){
        cin>>p;
    }
    if(b==1){
        cout<<1;
    }
    if(b==a){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
