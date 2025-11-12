#include<bits/stdc++.h>
using namespace std;
const int N=10e6+10;
char s[N];
char num[N];
bool cmp(char x,char y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<strlen(s);i++){
        if(s[i]<='9' && s[i]>='0') num[strlen(num)]=s[i];
    }
    sort(num,num+strlen(num),cmp);
    cout<<num;

    return 0;
}
