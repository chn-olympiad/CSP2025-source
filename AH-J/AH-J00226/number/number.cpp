#include<bits/stdc++.h>
using namespace std;
string a;
long long t[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            t[a[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=t[i];j++){
            cout<<i;
        }
    }
    return 0;
}
