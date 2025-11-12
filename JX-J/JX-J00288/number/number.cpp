#include<bits/stdc++.h>
using namespace std;
char ch;
int top;
int a[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>ch){
        if(ch>='0'&&ch<='9'){
            a[++top]=ch-'0';
        }
    }
    sort(a+1,a+1+top);
    for(int i=top;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
