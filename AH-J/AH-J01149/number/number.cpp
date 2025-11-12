#include<bits/stdc++.h>
using namespace std;
string s;
int a[100];
int h;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<(int)s.size();i++){
        if(isdigit(s[i])){
            a[s[i]-'0']++;
        }
    }
    for(int i=10;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    cout<<endl;
    return 0;
}
