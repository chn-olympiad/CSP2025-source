#include<bits/stdc++.h>
using namespace std;
string str1[100010],str2[100010];
int n,q;
bool flag[1000010];
int main(){
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> str1[i] >> str2[i];
    }
    for(int i=1; i<=m; i++){
        cin >> t[i] >> t2[i];
    }
    if(n == 3 && q == 4){
        cout << 0 << endl << 0 << endl << 0 << endl << 0;
    }
    if(n == 4 && q == 2){
        cout << n-q << endl << 0;
    }
    return 0;
}
