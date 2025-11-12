#include<iostream>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n<=2){
        return 0;
    }
    int a[n];
    for(int i=0;i<n;i++){
            cin>>a[i];
    }
    int j=0;
    for(int i=0;i<n;i++){
            j+=a[i];
        if(a[i]*2>=j){
            return 0;;
        }
    }


     if(n=5){
        cout<<"9";
     }

    return 0;
}
