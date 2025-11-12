#include<bits/stdc++.h>
using namespace std;
const int mn=1e6+10;
int a[mn];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int d=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='a'&&s[i]<='z'){
            continue;
        }else{
            a[i]=s[i]-'0';
            d++;
        }
    }
    sort(a,a+d,cmp);
    for(int i=0;i<d;i++){
        cout<<a[i];
    }
    return 0;
}
