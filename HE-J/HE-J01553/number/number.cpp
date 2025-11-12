#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int b=0;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(int i=57;i>=48;i--){
        while(b<100){
            if(a[b]==i){
                cout<<a[b];
            }
            b++;
        }
        b=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


