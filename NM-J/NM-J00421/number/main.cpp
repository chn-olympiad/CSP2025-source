#include <bits/stdc++.h>

using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string mya;
    vector<char> newa;
    cin>>mya;
    int j=0;
    for(int i=0;i<mya.size();i++){
        if(mya[i]>='0' && mya[i]<='9'){
           newa.push_back(mya[i]);
        }
    }
    sort(newa.begin(),newa.end());
    for(int i=newa.size()-1;i>=0;i--){
        cout<<newa[i];
    }
    return 0;
}
