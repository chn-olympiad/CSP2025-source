#include<bits/stdc++.h>
using namespace std;
string s;
int k;
int a[1000005];
void get(){
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9')a[++k]=s[i]-'0';
    }
}
bool bj(int a,int b){
    if(b>a)return 0;
    return 1;
}
void print(){
    for(int i=1;i<=k;i++)cout<<a[i];
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    get();
    sort(a+1,a+1+k,bj);
    print();
    return 0;
}
