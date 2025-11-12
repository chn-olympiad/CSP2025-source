#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int a,b,c;
    cin>>a>>b>>c;
    int d,e,f;
    int g,h=1e9;
    for(g=0;g<b;g++){
        cin>>d>>e>>f;
        h=min(h,f);
    }
    cout<<h;
    return 0;
}
