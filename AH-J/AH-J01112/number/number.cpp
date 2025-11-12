#include<bits/stdc++.h>
using namespace std;

int out[10] = {};
string n;

int main(){
	freopen("number.in" ,"r" ,stdin );
	freopen("number.ans","w" ,stdout);

    getline(cin, n);

    for(char i:n){
        if(i>='0' && i<='9'){
            out[i-'0'] ++;
        }
    }

    for(int i=9; i>=0; i--){
        for(int j=0; j<out[i]; j++){
            cout << i;
        }
    }

    fclose(stdin );
    fclose(stdout);
    return 0;
}
