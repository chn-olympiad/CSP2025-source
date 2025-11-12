#include<bits/stdc++.h>
#define ll long long
using namespace std;


string s;
ll a[1000010];

int main(){


    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin >> s;
    int cnt = 0;
    for(int i = 0;i <= 1000001;i++){
        if(s[i] == '0'){
            cnt++;
            a[cnt] = 0;
        }else if(s[i] == '1'){
            cnt++;
            a[cnt] = 1;
        }else if(s[i] == '2'){
            cnt++;
            a[cnt] = 2;
        }else if(s[i] == '3'){
            cnt++;
            a[cnt] = 3;
        }else if(s[i] == '4'){
            cnt++;
            a[cnt] = 4;
        }else if(s[i] == '5'){
            cnt++;
            a[cnt] = 5;
        }else if(s[i] == '6'){
            cnt++;
            a[cnt] = 6;
        }else if(s[i] == '7'){
            cnt++;
            a[cnt] = 7;
        }else if(s[i] == '8'){
            cnt++;
            a[cnt] = 8;
        }else if(s[i] == '9'){
            cnt++;
            a[cnt] = 9;
        }
    }
    sort(a + 1,a + cnt + 1,greater<int>());

    for(int i = 1;i <= cnt ;i++){
        cout << a[i];
    }

    return 0;
}
