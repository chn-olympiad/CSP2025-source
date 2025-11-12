#include<bits/stdc++.h>
using namespace std;
int num[15];
string a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.length();i++){
        if(a[i]<='9'&&a[i]>='0') num[a[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(num[i]){
            cout<<i;
            num[i]--;
        }
    }
    return 0;
}
