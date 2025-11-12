#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char c;
    while(cin>>c){
        if(c>='0'&&c<='9') a[c-'0']++;
    }
    string s;
    for(int i=9;i>=0;i--){
        while(a[i]) {
            s+='0'+i;
            a[i]--;
        }
    }
    cout<<s;
    return 0;
}
