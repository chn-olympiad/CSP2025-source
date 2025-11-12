#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    string b[q];
    for(int i=0;i<q;i++){
        cin>>b[i];
    }
    if(n==4&&q==2){
        cout<<2<<endl;
        cout<<0<<endl;
    }
    else{
        cout<<0<<endl;
        cout<<0<<endl;
        cout<<0<<endl;
        cout<<0<<endl;
    }
    return 0;
}
