#include<bits/stdc++.h>
using namespace std;
string str;
int num[1000005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;
    int l=str.size(),pos=0;
    for(int i=0;i<l;i++){
        if(str[i]>='0' && str[i]<='9'){
            pos++;
            num[pos]=str[i]-'0';
        }
    }
    sort(num+1,num+1+pos,cmp);
    for(int i=1;i<=pos;i++) cout<<num[i];
    return 0;
}
