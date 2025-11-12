#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t = 0;
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int maxx=0;
    cin>>t;
    for(int i = 0;i<t,t++){
        cin>>n;
        for(int j = 0;j<n;j++){
            cin>>a>>b>>c;
            d=max(a,b,c);
            maxx+=d;
        }
        cout<<maxx;
    }
    return 0;
}
