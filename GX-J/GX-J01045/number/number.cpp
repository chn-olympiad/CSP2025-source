#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s ="";
    char s1[1005] = {""};
    cin>> s;
    int coun = 0;
    for(int i = 0; i<s.length(); i++){
        if(s[i] >= '0' and s[i]<='9'){
            s1[coun] = s[i];
            coun++;
        }
    }
    for(int i = 0; i<1005; i++){
        for(int j = i; j<1005; j++){
            if(s1[i] < s1[j]){
                swap(s1[i], s1[j]);
            }
        }
    }
    cout<< s1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
