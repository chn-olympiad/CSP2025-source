#include<bits/stdc++.h>
using namespace std;
string a;
int b[15];
bool zg=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9')b[int(a[i]-'0')]++;
    }
    for(int i=9;i>=0;i--){
        if(zg==0&&i==0){
            cout<<0;
            break;
        }
        while(b[i]--){
            printf("%d",i);
            zg=1;
        }
    }
    return 0;
}
//g++ number.cpp -o number -O2 -std=c++14
