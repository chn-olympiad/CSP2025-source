#include<bits/stdc++.h>
using namespace std;
string n;
long long k=1,m[10],ans=0;
bool zero=1;
int main(){
    freopen("number.out","w",stdout);
    freopen("number.in","r",stdin);
    cin>>n;
    for(int i=0;i<n.size();i++){
        if(n[i]>=48 && n[i]<=57){
            if(n[i]!=48) zero=0;
            m[n[i]-48]++;
        }
    }
    if(zero==1){
        cout<<0;
        return 0;
    }
    else{
        for(int i=10;i>=0;i--){
            for(int j=1;j<=m[i];j++){
                cout<<i;
            }
        }
    }
    return 0;
}
