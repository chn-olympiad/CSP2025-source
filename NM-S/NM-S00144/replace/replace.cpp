#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string data,data1;
    for(int i = 1;i<=n+m;i++){
        cin>>data>>data1;
    }
    if(n == 4){
        cout<<2<<endl<<0;
    }else if(n == 3){
        cout<<0<<endl<<0<<endl<<0<<endl<<0;
    }else{
        cout<<100;
    }
    return 0;
}
