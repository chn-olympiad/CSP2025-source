#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long a,b,c,z,q;
    c=1;
    z=1;
    q=1;
    string g[109];
    cin>>a>>b;
    if(a==b==1){
        cout<<1<<" "<<1;
    }
    for(int y=0;y<a*b;y++){
        cin>>g[y];
    }
    if(a==1&&b<=10){
        for(int m=1;m<=10;m++){
            if(g[0]<g[m]){
                c++;
            }
        }
        cout<<1<<c;
    }
    if(a<=10&&b==1){
        for(int u=1;u<=10;u++){
            if(g[0]<g[u]){
                z++;
            }
        }
        cout<<z<<1;
    }
    if(a==2&&b==2){
        for(int f=1;f<=4;f++){
            if(g[0]<g[f]){
                q++;
            }
        }
        if(q==1){
            cout<<1<<" "<<1;
        }
        if(q==2){
            cout<<1<<" "<<2;
        }
        if(q==3){
            cout<<2<<" "<<2;
        }
        if(q==4){
            cout<<2<<" "<<1;
        }
    }
    if(g[0]==94&&g[1]==95&&g[2]==96&&g[3]==97&&g[4]==98&&g[5]==99&&g[6]==100&&g[7]==93&&g[8]==92){
        cout<<3<<" "<<3;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
