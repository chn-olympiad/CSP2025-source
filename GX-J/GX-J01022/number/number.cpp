#include<bits/stdc++.h>
using namespace std;

int arr[10];
char s[1000005];
char num[11] = "0123456789";

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin>>s;
    int len = strlen(s);
    for(int i=0; i<=len; i++){
        for(int j=0; j<=9; j++){
            if(s[i]==num[j]){
                arr[j]++;
                break;
            }
        }
    }
    for(int i=9; i>=0; i--){
        for(int j=1; j<=arr[i]; j++){
            cout<<num[i];
        }
    }
    return 0;
}
