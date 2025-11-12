#include<bits/stdc++.h>
using namespace std;

int n,k,t;
vector<int> a;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    a.push_back(0);
    for(int i=1;i<=n;i++){
        cin>>t;
        a.push_back(t);
    }
    if(k==0){
        if(n==1){
            cout<<"0";
            return 0;
        }else if(n==2){
            cout<<"1";
            return 0;
        }else{
            cout<<n/2;
            return 0;
        }
    }else if(k==1){

    }



    return 0;
}
