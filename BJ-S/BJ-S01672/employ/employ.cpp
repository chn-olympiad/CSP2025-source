#include <bits/stdc++.h>
using namespace std;

int n,m;
string str;
bool special_A=true;

int pluss(int x){//阶乘
    int result=1;
    for (;x!=0;x--){
        result*=x;
        result%=998244353;
    }
    return result;
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    int arr[n];
    cin >> str;
    for (int i=0;i<n;i++){
        cin >> arr[i];
        if (str[i]=='0'){
            special_A=false;
        }
    }
    //0-clean
    int dead=0;
    bool flag;
    for (int i=0;i<n;i++){
        if (i==0) flag=false;
        if (arr[i]<=dead && arr[i]!=-1){
            dead++;
            arr[i]=-1;
            flag=true;
        }
        if (i==n-1 && flag) i=-1;
    }
    n-=dead;
    //

    if (special_A==true){
        if (n>=m) cout << pluss(n);
        else cout << 0;
    }
    else {
        cout << "I love YYN";
    }

    return 0;
}
