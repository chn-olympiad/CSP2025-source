#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,ans,x;
int main(){
        freopen("road.in","r",stdin);
        freopen("road.out","w",stdout);
        cin>>n>>m>>k;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=2;j++){
                cin>>x;
            }
            cin>>x;
            ans+=x;
        }
        cout<<ans;
        return 0;
}







