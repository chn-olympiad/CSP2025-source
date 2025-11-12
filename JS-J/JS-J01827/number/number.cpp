#include<bits/stdc++.h>
using namespace std;
int a[1000010],t=1;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=s.size();
    for(int i=0;i<=l-1;i++){
        if(s[i]<='9'&&s[i]>='0'){
            a[t]=s[i]-'0';
            t++;
        }
    }
    sort(a+1,a+t,cmp);
    for(int i=1;i<=t-1;i++){
        cout<<a[i];
    }
    return 0;
}
