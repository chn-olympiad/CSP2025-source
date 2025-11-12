#include <iostream>
using namespace std;
#include <string>
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    cin>>n;
    for(int i=0;i<n.length();i++){
        if(n[i]>=n[i+1]){
            if(n[i]>='0' && n[i]<='9'){
                cout<<n[i];
            }
        }
        else if(n[i]>='0' && n[i]<='9'){
            cout<<n[i+1];
        }
    }
    return 0;
}
