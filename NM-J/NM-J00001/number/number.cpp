#include <iostream>
#include <string>
#include <cstdio>
int list[11];
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    cin>>n;
    for(int i = 0; i < n.size(); i++){
        if(n[i] >= '0' && n[i] <= '9'){
            list[n[i]-'0']++;
        }
    }
    for(int i = 9; i >= 0; i--){
        if(list[i] > 0){
            for(int j = 1; j <= list[i]; j++){
                cout<<i;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

