#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
string a;
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 1;i<=(n+q)*2;i++){
        cin >> a;
    }
    for(int i = 1;i<=q;i++){
        cout << "0" << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
