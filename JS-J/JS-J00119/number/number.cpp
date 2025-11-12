#include <bits/stdc++.h>
using namespace std;

char c;
vector <int> arr;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","a",stdout);
    while(cin >> c){
        if(c >= '0'&&c <= '9'){
            arr.push_back(c-'0');
        }
    }
    int len = arr.size();
    for(int i = 0;i < len-1;i++){
        int max = arr[i];
        for(int j = i+1;j < len; j++){
            if(arr[j] > arr[i]){
                swap(arr[i],arr[j]);
            }
        }
    }
    for(int i = 0;i < len;i++){
        cout << arr[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
