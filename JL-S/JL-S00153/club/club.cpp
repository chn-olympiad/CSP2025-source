#include <iostream>
using namespace std;
struct bumen{
    int yi;
    int er;
    int san;

};
int main(){
    int t,n;
    cin>>t>>n;
    for(int i=0;i<=t;i++){
        bumen a[1000];
        int da1=0,da2=0,da3=0;
        for(int i=0;i<=n;i++){
            cin>>a[i].yi>>a[i].er>>a[i].san;
        }
        for(int i=0;i<=n;i++){
            if(a[i].yi>da1) da1=a[i].yi;
        }
        for(int i=0;i<=n;i++){
            if(a[i].er>da2) da2=a[i].er;
        }
        for(int i=0;i<=n;i++){
            if(a[i].san>da3) da3=a[i].san;
        }
        cout<<da1+da2+da3;
    }
    return 0;
}
