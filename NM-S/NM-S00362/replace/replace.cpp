#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 1;i<=n;i++){
        cin >> s1 >> s2;
    }
    for(int i = 1;i<=q;i++){
        if(s1.size() % 2 == 0){
            cout << 0 << endl;
        }
        else if(s1.size() % 2 != 0){
            cout << 1 << endl;
        }
        if((s2.size() + s1.size()) % 2 == 0){
            cout << n*2 << endl;
        }
        else if((s2.size() + s1.size()) % 2 != 0){
            cout << n << endl;
        }
    }

    return 0;
}
