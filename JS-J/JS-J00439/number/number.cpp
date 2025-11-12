#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    cin>>n;
    for(int i=0;i<n.length();i++){
        if(n[i]<='9'&&n[i]>='0'){
            m[n[i]-48]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<m[i];j++){
            cout<<i;
        }
    }
    return 0;
}
