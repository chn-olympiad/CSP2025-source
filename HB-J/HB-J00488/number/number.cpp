#include<bits/stdc++.h>
using namespace std;
int ton[11];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout); 
    string in;
    cin >> in;
    int js = 0;
    for(int i = 0;i < in.size();i++){
        int tmp = -1;
        if(in[i] >= '0' && in[i] <= '9'){
            tmp = int(in[i]) - 48;
            ton[tmp]++;
            js++;
        }
    }
    for(int i = 9;i >= 0;i--){
        for(int j = 1;j <= ton[i];j++){
            cout << i;
        }
    }
    cout << endl;
    return 0;
}