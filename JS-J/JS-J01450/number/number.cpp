#include<iostream>
using namespace std;

char c[1000005];
int a[15];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>c;
    for(int i=0;c[i];i++){
        if(c[i]>=48 && c[i]<=57){
            a[c[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }



    return 0;
}
