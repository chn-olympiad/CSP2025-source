#include <bits/stdc++.h>
using namespace std;
vector<char> b;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char i;
    while(cin>>i){
        if('0'<=i&&i<='9'){
            b.push_back(i);
        }
    }
    sort(b.rbegin(),b.rend());
    for(char j:b){
        cout<<j;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

