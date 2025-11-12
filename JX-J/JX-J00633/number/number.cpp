#include<iostream>
#include<cstring>
using namespace std;
int a[10100];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string b,c;
    int d=1,f;
    cin>>b;
    for(int i=0;i<=b.size()-1;i++){
        if(b[i]>='0' and b[i]<='9'){
            a[d]=int(b[i]);
            d++;
        }
    }
    for(int i=57;i>=48;i--){
        for(int j=1;j<=d;j++){
            if(a[j]==i){
                cout<<char(a[j]);
            }
        }
    }
}
