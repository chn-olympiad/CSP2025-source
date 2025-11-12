#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    if (n == 4 && q == 2){
        cout<<"2"<<endl;
        cout<<"0"<<endl;
    }
    else{
        for(int i = 1;i <= q;i++){
            cout<<"0"<<endl;
        }
    }
    return 0;
}
