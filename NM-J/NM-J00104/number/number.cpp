#include<bits/stdc++.h>
use namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a,cnt = 1;
    cin>>a;
    while(true){
        if(a%10 < 10){
            break;
        }
        else{
            cnt = cnt*10;
            continue;
        }
    }
    for(int i = 9;i>=0;i--){
    `   for(int j = 0;j <= cnt*10;j++){
            if(a[j] == i){
                cout<<a[j];
            }
        }
    }
    fclose(stdin);
    fclose(stdin);
    return 0;
}
