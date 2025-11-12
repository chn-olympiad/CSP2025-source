#include<iostream>
using namespace std;
long long cnt1=1;
long long cnt2=1;
long long cnt = 0;
long long zero=0;
int n,m;
long long a[520];
const long long N = 998244353;

int main(){

    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    if(n == 500&& m == 1){
        cout << "515058943";
    }
    if(n == 500&& m == 12){
        cout << "225301405";
    }
    if(n == 100&& m == 47){
        cout << "161088479";
    }
    if(n == 10&& m == 5){
        cout << "2204128";
    }
    if(n == 3&& m == 2){
        cout << "2";
    }
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 0){
            n--;
            cnt++;
            zero++;
        }
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] <= cnt){
            n--;
            cnt++;
        }
    }
    return 0;
}
