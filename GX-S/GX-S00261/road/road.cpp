#include <bits/stdc++.h>
using namespace std;
long long d,e,f,mx=-1;
long long a[1000000],b[1000000],c[1000000];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>d>>e>>f;
    if(f==0){
        cout<<d*e;
    }else{
        for(int i=1;i<=e*3;i++){
            cin>>a[i];
        }
        for(int i=1;i<=f;i++){
            for(int j=1;j<=5;j++){
                cin>>b[j];
                c[i]+=b[j];
            }
        }
        for(int i=1;i<=f;i++){
            mx=max(mx,c[i]);
        }
        cout<<mx;
    }
    return 0;
}
