#include<bits/stdc++.h>
using namespace std;
bool amp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[100005]={0},p=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'<=25){
            a[p]=s[i]-'0';
            p++;
        }
    }
    sort(a,a+p,amp);
    for(int i=0;i<p;i++){
        cout<<a[i];
    }
    return 0;
}
