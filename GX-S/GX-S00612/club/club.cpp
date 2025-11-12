#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        int mx=-1;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a>>b>>c;
            mx+=max(a,max(b,c));
        }
        cout<<mx<<endl;
    }
    return 0;
}
