#include<bits/stdc++.h>
using namespace std;

string s;
char p[1000005]={};
int top=0;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++){
        char a=s[i];
        if('0'<=a && a<='9'){
            top++;
            p[top]=a;
        }
    }
    sort(p,p+top+1);
    for(int i=top;i>=1;i--){
        cout<<p[i];
    }
    return 0;
}
