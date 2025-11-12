#include <bits/stdc++.h>
using namespace std;
int f[100];
int main(){
    freopen("polygon.in","r",stdin)
    freopen("polygon.out","w",stdout)
    int a,b=0;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>f[i];
        if(f[i]<3){
            b++
        }
    }
    cout<<a*2-b
return 0;
}


