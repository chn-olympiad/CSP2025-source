#include<bits/stdc++.h>
using namespace std;
int f[500010],z[10010][25],kk[25],zui[25],fei=0,ddd=1;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,b,c=0,d,e,te=0,jian=0;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>f[i];
    }
    if(f[1]+f[2]>f[3]&&f[1]+f[3]>f[2]&&f[2]+f[3]>f[1]){
        cout<<"1";
        return 0;
    }
    cout<<"0";
    return 0;
}
