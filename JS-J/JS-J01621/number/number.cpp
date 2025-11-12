#include<bits/stdc++.h>
using namespace std;
int tong[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int l = s.size();
    for(int i = 0; i < l; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            int x = s[i]-'0';
            tong[x]++;
        }

    }
    for(int i = 9; i >= 0; i--){
        if(tong[i]!= 0){
            for(int j = 1; j <= tong[i]; j++){
                printf("%d",i);
            }
        }
    }
    printf("\n");
    return 0;
}
