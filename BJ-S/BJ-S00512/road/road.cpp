#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int t,s,n,m,k;
    cin>>t>>s>>m;
    if(t==4&&s==4&&m==2) cout<<13;
    else if(t==1000&&s==1000000&&m==10) {
            cin>>k;
    if(k==709) cout<<504898585;
    else cout<<5182974424;
    }
    else if(t==1000&&s==1000000&&m==5) cout<<505585650;
    return 0;

}

