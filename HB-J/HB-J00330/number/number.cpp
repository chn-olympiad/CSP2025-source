#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s, ans;
    int arr[10] = {0};
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if('0' <= s[i] && s[i] <= '9'){
            arr[s[i] - '0']++;
        }
    }
    for(int i = 9; i >= 0; i--){
        if(arr[i] != 0){
            while(arr[i]){
                ans.push_back(i + '0');
                arr[i]--;
            }

        }
    }
    cout << ans;

    fclose(stdin); fclose(stdout);
}
