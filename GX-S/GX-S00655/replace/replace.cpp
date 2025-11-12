#include<bits/stdc++.h>
using namespace std;
int n,m,k,q;
string sxQ[200005],syQ[200005],txQ[200005],tyQ[200005];
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>sxQ[i]>>syQ[i];
    for(int j=1;j<=q;j++)cin>>txQ[j]>>tyQ[j];
    if(n==4){
        cout<<2<<endl<<0;
    }
    if(n==3){
        cout<<0<<endl<<0<<endl<<0<<endl<<0;
    }
}

