#include <bits/stdc++.h>
using namespace std;
int s[999];
int m[999];
int main(){
    int n;
    cin >> n;
    for(int i = 0;i <= n;i++){
        cin >> s[i];
        if(i <= 9){
            int s[i] = m[i];
            for(int j = 0;j <= n;j++){
                if(j == 0){
                }
                if(j > 0){
                    if(m[j] > m[j-1]){
                        m[j] = m[j-1];
                        m[j-1] = m[j];
                    }
                }
            }
        }
    }
    for(int i = 0;i <= j;i++){
        cout << m[i];
    }
    return 0;
}