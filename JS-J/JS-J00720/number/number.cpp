#include<bits/stdc++.h>
using namespace std;
bool f(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string x;
    int xl[1000005],s=0;
    cin>>x;
    for(int i=0;i<=x.size();i++){
        if(x[i]>='0'&&x[i]<='9')xl[s++]=x[i]-'0';
    }
    sort(xl,xl+s,f);
    for(int i=0;i<s;i++)cout<<xl[i];
    return 0;
}
