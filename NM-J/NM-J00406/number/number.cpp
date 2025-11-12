#include<bits/stdc++.h>
using namespace std;
long long p[50];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a;
    while(cin>>a){
        if (int(a)>=48&&int(a)<=57){
            p[int(a)-48]++;
        }
    }
    for (int i=9;i>=0;i--){
        for (int j=1;j<=p[i];j++){
            cout<<i;
        }
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
