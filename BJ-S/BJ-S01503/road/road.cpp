#include <bits/stdc++.h>
using namespace std;
int a,b,c,sum,d;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>a>>b>>c;
    for(int i=1;i<=b;i++){
        cin>>a>>d>>c;
        sum+=c;
    }
    cout<<sum;
}
