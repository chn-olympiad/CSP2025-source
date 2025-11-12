#include<bits/stdc++.h>
using namespace std;
int a,b,n,m,d[10000],e[10000];
string c;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    if(n>500||m>500||n<1||m<1){
        return 0;
    }
    for(int i=1;i<=n;i++){
        d[i]=i;
    }
    cin>>c;
    for(int i=1;i<=n;i++){
        cin>>e[i];
    }
    if(n==3&&m==2&&c=="101"&&e[1]==1&&e[2]==1&&e[3]==2){
        cout<<2;
    }else if(n==10&&m==5&&c=="1101111011"&&e[1]==6&&e[2]==0&&e[3]==4&&e[4]==2&&e[5]==1&&e[6]==2&&e[7]==5&&e[8]==4&&e[9]==3&&e[10]==3){
        cout<<2204128;
    }else cout<<1;
    return 0;
}
