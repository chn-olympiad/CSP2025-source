#include<iostream>
#include<map>
#include<string>
using namespace std;

int b[10];
int main(){
    #ifndef zhouyi
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a;
    cin>>a;
    for(auto i:a){
        if('0'<=i&&i<='9')b[i-'0']+=1;
    }
    int Max=10;
    for(int i=9;i>=0;--i){
        for(int j=0;j<b[i];++j){
            if(Max==0)break;
            cout<<i;
            Max=Max>i?Max:i;
        }
    }
    return 0;
}