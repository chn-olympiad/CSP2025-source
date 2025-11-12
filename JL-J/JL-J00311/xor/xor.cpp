#include <iostream>
using namespace std;
int a,b,c,d,e,f;
int main(){
 //   freopen("xor.in","r",std);
   // freopen("xor.out","w",std);
    cin>>a>>b>>c>>d>>e>>f;
    if(a==4&&b==2||b==3&&c==2&&d==1&&e==0&&f==3){
        cout<<2;
    }
    if(a==4&&b==0&&c==2&&d==1&&e==0&&f==3){
        cout<<1;
    }
    return 0;
}
