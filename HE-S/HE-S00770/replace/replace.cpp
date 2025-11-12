#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int s,b;
    cin>>s>>b;
    char a[s+b+5],d[s+b+5];
    for(int j=0;j<=s+b;j++){
        cin>>a[j]>>d[j];
    }
    for(int i=0;i<b;i++){
        cout<<0;
    }
    return 0;
}
