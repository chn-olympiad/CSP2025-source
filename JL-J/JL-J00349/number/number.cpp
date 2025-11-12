#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

int num[10];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;cin>>a;
    for(int i=0;i<=a.size();i++){
        if(a[i]<='9' &&a[i]>='0'){
            int xb=a[i]-'0';
            num[xb]++;
        }
    }
    for(int i=9;i>=0;i--){
        while(num[i]){
            cout<<i;
            num[i]--;
        }
    }
    return 0;
}
