#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s;
    char s1[1000001];
    char hc;
    int k = 0;
    while (cin>>s){
        s1[k] = s;
        if (s1[k] < '0' || s1[k] < 'a' || s1[k] > 'z' || s1[k] > '9'){
            break;
        }
        k++;
    }
    for (int i = 1;i < k;i++){
        for (int j = 0;j < k;j++){
            if (s1[k] < '0' || s1[k] > '9'){
                continue;
            }
            hc = min(s1[j],s1[j-1]);
            s1[j-1] = max(s1[j],s1[j-1]);
            s1[j] = hc;
        }
    }
    for (int i = 0;i < k;i++){
        cout << s1[i];
    }
}
