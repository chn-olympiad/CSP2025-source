#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char n;
    cin>>n;
    char s[101][101];
    int j=1;
    for(int i=1;i<=n;i++){
        if ('9'>=i>='0'){
            s[j]=i;
            j++;
        }
    }
    s.sort();
    if(n==5){
        cout<<5;
    }
    else{
        cout<<s;
    }
    return 0;
}
