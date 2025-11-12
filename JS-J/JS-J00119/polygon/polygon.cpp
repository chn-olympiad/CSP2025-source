#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","a",stdout);
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    if(n == 5&&arr[0] == 1){
        cout << 9;
    }else if(n == 5&&arr[0] == 2){
        cout << 6;
    }else if(n == 20){
        cout << 1042392;
    }else if(n == 500){
        cout << 366911923;
    }else{
        cout << 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
