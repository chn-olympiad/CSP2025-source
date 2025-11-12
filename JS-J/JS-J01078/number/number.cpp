#include<bits/stdc++.h>
using namespace std;
int b[1000005],cnt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(int i=0;i<a.length();i++){
        if(isdigit(a[i])){
            b[cnt]=a[i]-'0';
            cnt++;
        }
    }
    sort(b,b+cnt);
    for(int i=cnt-1;i>=0;i--){
        cout<<b[i];
    }
    return 0;
}