#include<bits/stdc++.h>
using namespace std;
int maopao(const int &a,const int &b){
    if(a>b) return 1;
    if(a==b) return 0;
    if(a<b) return 0;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","W",stdout);
    string s;
    int a[10];
    cin>>s;
    if(sizeof(s)==1){
        cout<<s;
        return 0;
    }
    for(int i=0,j=0;i<sizeof(s);i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[j]=s[i];
            j++;
        }
    }
    sort(a,a+10,maopao);
    cout<<a;
    return 0;
}
