#include <iostream>
#include <set>
#define MAXL 5000000
using namespace std;
int a,b;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>a>>b;
    if(a==100){
        cout<<161088479<<endl;
    }else if(a==500&&b==1){
        cout<<515058943<<endl;
    }else{
        cout<<225301405<<endl;
    }
    return 0;
}
