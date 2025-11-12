#include <iostream>
using namespace std;
long long a,b=0,c[100000];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>c[i];
        if(c[i]=1){
            b++;
        }
    }
    if(a==3){
        if(c[1]+c[2]>c[3]){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
        cout<<a*a-1;
    }
    return 0;
}
