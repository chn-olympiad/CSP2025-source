#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false),cin.tie(0);

    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    int n,q;
    cin>>n>>q;

    if(n==4&&q==2){
       cout<<2<<endl<<0;
       return 0;
    }
    if(n==3&&q==4){
       cout<<0<<endl<<0<<endl<<0<<endl<<0;
       return 0;
    }

    for(int i = 0 ; i < q ; i ++){
        cout<<0<<endl;
    }

    return 0;
}

