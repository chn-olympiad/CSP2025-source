#include<bits/stdc++.h>
using namespace std;
int t[150];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    cin>>n;
    for(int i=0;i<n.size();i++){
        if(n[i]>='a'&&n[i]<='z'){
            n.erase(i,1);
        }
        t[n[i]]++;
    }
    for(int i='9';i>='0';i--){
        for(int j=1;j<=t[i];j++){
            cout<<(i-'0');
        }
    }
    return 0;
}
//
