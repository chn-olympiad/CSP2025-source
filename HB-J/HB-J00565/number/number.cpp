#include <bits/bits/stdc++.h>
using namespace std;

char s[1000001];
int a[1000001],n;

int main(){
    cin >> s;
for(int i = 1;i <= 1000001;i++){
    if(s[i] == 0)
        n++;
        break;
    else
    if(s[i] >= '0' && s[i] <= '9'){
        a[i] = s[i] - '0';
        n++;
    }
}
for(int i = 1;i <= n;i++)
    for(int j = 1;j <= n;j++)
        if(a[j] < a[j + 1]){
            t = a[j];
            a[j] = a[j + 1];
            a[j + 1] = t;
        }
for(int i = 1;i <= n;i++){
    cout << a[i];
}
return 0;
}
