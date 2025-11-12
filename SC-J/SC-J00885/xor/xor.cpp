#include<bits/stdc++.h>
using namespace std;
int n, k, a[500005], num;
bool tmp = true, temp = true;
int main(){
     freopen("xor.in", "r", stdin);
     freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        if(a[i] != 1) tmp = false;
        if(a[i] != 1 && a[i] != 0) temp = false;
    }
    if(k == 0 && tmp) num = n / 2;
    else if(k == 1 && temp){
        for(int i = 1; i <= n; i ++)
            if(a[i] == 1){
                num ++;
                if(a[i + 1] == 0) i ++; 
            }
    }
    else if(k == 0 && temp){
        for(int i = 1; i <= n; i ++){
            if(a[i] == 1 && a[i + 1] == 1){num ++; i ++;}
            else if(a[i] == 0) num ++;
        }
    }
    cout << num; 
     fclose(stdin);
     fclose(stdout);
    return 0;
}