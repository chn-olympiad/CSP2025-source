#include <iostream>
using namespace std;
const int MAXN=1e6+1;
string a; 
int mp[10];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> a;
    for(int i=0;i<a.size();i++){
        int org=a[i]-'0';
        if(org>=0 && org<=9) mp[org]++;
    }
    for(int i=9;i>=0;i--){
        int wei=mp[i];
        for(int j=1;j<=wei;j++) cout << i;
    }
    return 0;
}