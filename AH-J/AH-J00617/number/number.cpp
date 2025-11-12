#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int b[10] = {0};
    cin >> a;
    int tool;
    for(int i = 0;i < a.size();i++){
        if(('0' <= a[i])&&(a[i] <= '9')){
            tool = a[i] - '0';
            b[tool]++;
        }
    }
    for(int i = 9;i >= 0;i--){
        while(b[i] >= 0){
            cout << i;
            b[i]--;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
