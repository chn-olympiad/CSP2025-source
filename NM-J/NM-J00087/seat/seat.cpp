#include <bits/stdc++.h>
using namespace std;
int n[999];

int main(){
    int s,m;
    cin >> s >> m;
    for(int i=0;i<=s*m;i++){
        cin >> n[i];
    }
    for(int i=1;i<=s*m;i++){
        int a = 1;
        int b = 1;
        if(a % 2 = 1){
            if(n[0] > n[i]){
                b += 1;
                if(b == m+1){
                    a += 1;
                    b = m;
                }
            }
        }else{
            if(n[0] > n[i]){
                b -= 1;
                if(b == 0){
                    a += 1;
                    b = 1;
                }
            }
        }
    }
    cout << a << " " << b;
    return 0;
}