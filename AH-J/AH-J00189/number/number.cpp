#include<bits/stdc++.h>
using namespace std;
string b[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int j=0;
    for(int i=0;i<a.length();i++){
        if(int(a[i])>=48&&int(a[i])<=57){
            b[j]=a[i];
            j++;
        }
    }
    sort(b,b+j);
    for(int i=j;i>=0;i--){
        cout<<b[i];
    }
    return 0;
}
