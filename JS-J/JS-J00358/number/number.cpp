#include<bits/stdc++.h>
using namespace std;
const int N=1e6+20;
int a[N]={},a1=0;
bool cmp(int l,int r){
     return l>r;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++a1]=s[i]-'0';
        }
    }
    sort(a+1,a+a1+1,cmp);
    for(int i=1;i<=a1;i++){
        cout<<a[i];
    }
    return 0;
}
