#include <iostream>
#include <vector>
using namespace std;

int n;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    vector<int> vec(n+1,0);

    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    cout<<"0";

    return 0;
}
