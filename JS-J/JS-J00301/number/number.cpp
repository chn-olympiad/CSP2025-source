#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string str;
char a[N];
int idx;
bool cmp(char x,char y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(str[i]>='0'&&str[i]<='9') a[idx++]=str[i];
    }
    sort(a,a+str.size(),cmp);
    for(int i=0;i<idx;i++) cout<<a[i];
    return 0;
}
