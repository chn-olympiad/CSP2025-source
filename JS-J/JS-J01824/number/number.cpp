#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n[10]={0},m=0;
    char a;
    while(cin>>a){
        if(a>='0' && a<='9'){
            n[a-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<n[i];j++){
            cout<<i;
        }
    }
    cout<<endl;
    return 0;
}
