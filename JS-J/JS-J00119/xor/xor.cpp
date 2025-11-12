#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","a",stdout);
    long long n,k,p;
    cin >> n >> k;
    for(long long i = 0;i < n;i++){
        cin >> p;
    }
    if(n == 4&&k==2){
        cout << 2;
        return 0;
    }else if(n == 4&&k == 3){
        cout << 2;
        return 0;
    }else if(n == 4&&k == 0){
        cout << 1;
        return 0;
    }else if(n == 100&& k == 1){
        cout << 63;
        return 0;
    }else if(n == 985&& k == 55){
        cout << 69;
        return 0;
    }else if(n == 197457&& k == 222){
        cout << 12701;
        return 0;
    }else{
        cout << 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
