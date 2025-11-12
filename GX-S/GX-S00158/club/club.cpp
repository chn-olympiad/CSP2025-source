#include<bits/stdc++.h>
using namespace std;
int ans=0,n,a,b,c,d,e,f;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>a>>b>>c>>d>>e>>f;
        cout<<max(a+e,max(a+f,max(b+d,max(f+b,max(c+d,c+e)))));
    }
}
