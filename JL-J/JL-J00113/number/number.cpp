#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int sum;
    for(int i=0;i<10000;i++){
        sum+=i;
        if ( s <= "10" ){
            cout<<s<<endl;
            return 0;
        }
        cout<<sum<<endl;
    }
    return 0;
}
