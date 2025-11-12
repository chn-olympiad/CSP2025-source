#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int l=0;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') a[l++]=s[i]-'0';
    }
    sort(a,a+l,cmp);
    for(int i=0;i<l;i++) cout<<a[i];
    return 0;
    //ac
}
