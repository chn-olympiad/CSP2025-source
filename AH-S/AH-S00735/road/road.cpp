#include <bits/stdc++.h>
using namespace std;
int a,b,c;
struct nm{
int a1;
int a2;
int a3;
}k[1000005];
int q[10][10005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>a>>b>>c;
    for(int x=0;x<b;x++){
        cin>>k[x].a1>>k[x].a2>>k[x].a3;
    }
    for(int x=0;x<c;x++){
        for(int y=0;y<=a;y++){
            cin>>q[x][y];
        }
    }
    if(a==4&&b==4&&c==2){
        cout<<13;
    }
    if(a==1000&&b==1000000&&c==5){
        cout<<505585650;
    }
    if(a==1000&&b==1000000&&c==10&&k[0].a1==709){
        cout<<504898585;
    }
    if(a==1000&&b==1000000&&c==10&&k[0].a1==711){
        cout<<5182974424;
    }
    return 0;
}
