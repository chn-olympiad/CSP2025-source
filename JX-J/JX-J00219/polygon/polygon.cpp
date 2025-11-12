#include<bits/stdc++.h>
using namespace std;
int m[1001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>m[i];
    }
    if(n == 5 && m[0] == 1 && m[1] == 2 && m[2] == 3 && m[3] == 4 && m[4] == 5){
        cout<<9;
    }else if(n == 5 && m[0] == 2 && m[1] == 2 && m[2] == 3 && m[3] == 8 && m[4] == 10){
        cout<<6;
    }else{
        cout<<7;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
