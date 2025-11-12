#include<bits/stdc++.h>
using namespace std;
int a[10],t;
bool cmp(int x,int y){
    return x>y;
}int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            t++;
            a[t]=s[i]-48;}
    }sort(a+1,a+1+t,cmp);
    if(a[1]==0){cout<<0;}
    for(int i=1;i<=t;i++){cout<<a[i];}
}
